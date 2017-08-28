#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define LOG_DBG(fmt, ...)   printf("%s:%d "fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define LOG_ERR(fmt, ...)   printf("[ERR] %s:%d "fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define LOG_ERR_errno(szFormat, ...)    \
                        do  \
                        {   \
                            int nErrno = errno; \
                            char szErrBuf[64] = {0};    \
                            strerror_r(nErrno, szErrBuf, sizeof(szErrBuf)); \
                            LOG_ERR(szFormat", errno %d{%s}\n",   \
                                            ##__VA_ARGS__, nErrno, szErrBuf); \
                        }while(0)


static int _RecvMulticastMsg(const char * szMultiIP, const int nMultiPort)
{
    int nRet = 0;
    int nSock = 0;
    int nRecvLen = 0;
    char szRecvBuf[4096] = {0};
    int nRecvBufSize = 0;
    struct sockaddr_in tSrcAddr = {0};
    socklen_t nAddrLen = 0;
    struct ip_mreq tMCast = {{0}};
    struct sockaddr_in tLocalAddr = {0};

    do
    {
        nSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if(nSock < 0)
        {
            LOG_DBG("socket() failed\n");
            nRet = 1;
            break;
        }

#if 0
        //指定当前IP所对应接口为组播接口
        memset(&tLocalAddr, 0, sizeof(tLocalAddr));
        tLocalAddr.sin_family = AF_INET;
    	tLocalAddr.sin_addr.s_addr = inet_addr("172.16.192.38");
    	if (setsockopt(nSock, IPPROTO_IP, IP_MULTICAST_IF, (void *)&tLocalAddr, sizeof(tLocalAddr)) < 0)
        {
            LOG_ERR_errno("setsockopt IP_MULTICAST_IF failed");
            nRet = 1;
            break;
        }
#endif

        memset(&tMCast, 0, sizeof(tMCast));
        tMCast.imr_multiaddr.s_addr = inet_addr(szMultiIP);
        tMCast.imr_interface.s_addr = inet_addr("172.16.192.38");
        nRet = setsockopt(nSock, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char *)&tMCast, sizeof(tMCast));
        if(nRet < 0)
        {
            LOG_ERR_errno("setsockopt() failed");
            nRet = 1;
            break;
        }

        //绑定端口
        memset(&tLocalAddr, 0, sizeof(tLocalAddr));
        tLocalAddr.sin_family = AF_INET;
    	tLocalAddr.sin_addr.s_addr = INADDR_ANY;
    	tLocalAddr.sin_port = htons(nMultiPort);
    	if(bind(nSock, (struct sockaddr *)&tLocalAddr, sizeof(tLocalAddr)) < 0)
    	{
    	    LOG_ERR_errno("bind() failed");
    	    nRet = 1;
            break;
    	}

        nRecvBufSize = sizeof(szRecvBuf);
        nAddrLen = sizeof(tSrcAddr);
        nRecvLen = recvfrom(nSock, szRecvBuf, nRecvBufSize, 0, 
                            (struct sockaddr *)&tSrcAddr, &nAddrLen);
        if(nRecvLen < 0)
        {
            LOG_DBG("recvfrom() failed\n");
            nRet = 2;
            break;
        }
        
        LOG_DBG("recv from{%s:%d}\n data %d{%.*s}\n", inet_ntoa(tSrcAddr.sin_addr), 
                                ntohs(tSrcAddr.sin_port), nRecvLen, nRecvLen, szRecvBuf);
        
        nRet = 0;

#define _SEND_ONVIF_PROBE_MATCH_
#ifdef _SEND_ONVIF_PROBE_MATCH_
        if(tSrcAddr.sin_addr.s_addr != inet_addr("172.16.193.152"))
        {
            LOG_DBG("not 192.152\n");
            break;
        }

        {
            int nII = 0;
            int nSendLen = 0;
            char szRespBodyBuf[1024 * 4] = {0};
            const char * szRespBodyFmt = "<?xml version=\"1.0\" encoding=\"utf-8\"?>"
                                        "<env:Envelope xmlns:tds=\"http://www.onvif.org/ver10/device/wsdl\" "
                                                "xmlns:env=\"http://www.w3.org/2003/05/soap-envelope\" "
                                                "xmlns:dn=\"http://www.onvif.org/ver10/network/wsdl\" "
                                                "xmlns:wsa=\"http://schemas.xmlsoap.org/ws/2004/08/addressing\" "
                                                "xmlns:d=\"http://schemas.xmlsoap.org/ws/2005/04/discovery\">"
                                            "<env:Header>"
                                                "<wsa:MessageID>uuid:4a53cb9d-1fda-4409-b22f-569004594d26</wsa:MessageID>"
                                                "<wsa:RelatesTo>uuid:d624d57c-8f17-4bb1-83f2-c062d165f56f</wsa:RelatesTo>"
                                                "<wsa:To>http://schemas.xmlsoap.org/ws/2004/08/addressing/role/anonymous</wsa:To>"
                                                "<wsa:Action>http://schemas.xmlsoap.org/ws/2005/04/discovery/ProbeMatches</wsa:Action>"
                                            "</env:Header>"
                                            "<env:Body>"
                                                "<d:ProbeMatches>"
                                                    "<d:ProbeMatch>"
                                                        "<wsa:EndpointReference>"
                                                            "<wsa:Address>urn:uuid:4b454441-cee2-b1f2-5690-0014100e%04x</wsa:Address>"
                                                        "</wsa:EndpointReference>"
                                                        "<d:Types>dn:NetworkVideoTransmitter tds:Device</d:Types>"
                                                        "<d:Scopes>onvif://www.onvif.org/Profile/Streaming "
                                                                    "onvif://www.onvif.org/Profile/G "
                                                                    "onvif://www.onvif.org/type/video_encoder "
                                                                    "onvif://www.onvif.org/type/audio_encoder "
                                                                    "onvif://www.onvif.org/type/ptz "
                                                                    "onvif://www.onvif.org/hardware/IPC425-E230-N "
                                                                    "onvif://www.onvif.org/name/baiucebdi2"
                                                        "</d:Scopes>"
                                                        "<d:XAddrs>http://172.16.192.38:80/onvif/device_service</d:XAddrs>"
                                                        "<d:MetadataVersion>1</d:MetadataVersion>"
                                                    "</d:ProbeMatch>"
                                                "</d:ProbeMatches>"
                                            "</env:Body>"
                                        "</env:Envelope>";
            for(nII = 0; nII < 512; nII++)
            {
                snprintf(szRespBodyBuf, sizeof(szRespBodyBuf), szRespBodyFmt, nII);
                nSendLen = sendto(nSock, szRespBodyBuf, strlen(szRespBodyBuf), 0, (struct sockaddr*)&tSrcAddr, sizeof(tSrcAddr));
                if(nSendLen < 0)
                {
                    printf("[%d][ERR] sendto failed, errno %d===============\n", nII, errno);
                }
                else
                {
                    printf("[%d] sendto ok\n", nII);
                }

                if((nII + 1) % 5 == 0)
                {
                    usleep(5 * 1000);
                }
            }
        }
#endif
    }while(0);

    return nRet;
}

int main(int argc, char ** argv)
{
    char * szMultiIP = NULL;
    int nMultiPort = 0;
    
    if(3 != argc)
    {
        LOG_DBG("./r multicast_ip port\n");
        return 1;
    }

    szMultiIP = argv[1];
    nMultiPort = atoi(argv[2]);

    LOG_DBG("multicast addr {%s:%d}\n", szMultiIP, nMultiPort);

    if(0 != _RecvMulticastMsg(szMultiIP, nMultiPort))
    {
        LOG_DBG("_RecvMulticastMsg() failed\n");
        return 2;
    }
    
    return 0;
}

