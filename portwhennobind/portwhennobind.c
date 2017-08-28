#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

static void UdpPortNotBind(int * pnBindPort)
{
    int nRet = 0;
    int nSock = 0;
    int nSendLen = 0;
    struct sockaddr_in tTmpAddr;
    socklen_t nTmpAddrLen = 0;

    nSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(nSock < 0)
    {
        printf("socket() failed, errno %d\n", errno);
        return;
    }

    memset(&tTmpAddr, 0, sizeof(tTmpAddr));
    tTmpAddr.sin_family = AF_INET;
    tTmpAddr.sin_addr.s_addr = inet_addr("172.16.193.151");
    tTmpAddr.sin_port = htons(1638);

    nSendLen = sendto(nSock, "hello", 6, 0, (struct sockaddr*)&tTmpAddr, sizeof(tTmpAddr));
    if(nSendLen < 0)
    {
        printf("sendto failed, errno %d\n", errno);
        close(nSock);
        return;
    }

    nTmpAddrLen = sizeof(tTmpAddr);
    nRet = getsockname(nSock, (struct sockaddr*)&tTmpAddr, &nTmpAddrLen);
    if(nRet < 0)
    {
        printf("getsockaddr failed, errno %d\n", errno);
        close(nSock);
        return;
    }

    //printf("nSock %d, {%s:%d}\n", nSock, inet_ntoa(tTmpAddr.sin_addr), ntohs(tTmpAddr.sin_port));
    *pnBindPort = ntohs(tTmpAddr.sin_port);
    close(nSock);
}

static void TcpPortNotBind(int * pnBindPort)
{
    int nRet = 0;
    int nSock = 0;
    int nSendLen = 0;
    struct sockaddr_in tTmpAddr;
    socklen_t nTmpAddrLen = 0;

    nSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(nSock < 0)
    {
        printf("socket() failed, errno %d\n", errno);
        return;
    }

    memset(&tTmpAddr, 0, sizeof(tTmpAddr));
    tTmpAddr.sin_family = AF_INET;
    tTmpAddr.sin_addr.s_addr = inet_addr("172.16.193.151");
    tTmpAddr.sin_port = htons(80);

    nRet = connect(nSock, (struct sockaddr*)&tTmpAddr, sizeof(tTmpAddr));
    if(nRet < 0)
    {
        printf("connect failed, errno %d{%s}\n", errno, strerror(errno));
        close(nSock);
        return;
    }

    nTmpAddrLen = sizeof(tTmpAddr);
    nRet = getsockname(nSock, (struct sockaddr*)&tTmpAddr, &nTmpAddrLen);
    if(nRet < 0)
    {
        printf("getsockaddr failed, errno %d\n", errno);
        close(nSock);
        return;
    }

    printf("nSock %d, {%s:%d}\n", nSock, inet_ntoa(tTmpAddr.sin_addr), ntohs(tTmpAddr.sin_port));
    *pnBindPort = ntohs(tTmpAddr.sin_port);
    close(nSock);
}

int main(int argc, char ** argv)
{
    int nBindPort = 0;
    int nII = 0;
    int nMin = 65535;
    int nMax = 0;

    for(nII = 0; nII < 65535; nII ++)
    {
        UdpPortNotBind(&nBindPort);
        if(nBindPort < nMin)
        {
            nMin = nBindPort;
        }

        if(nBindPort > nMax)
        {
            nMax = nBindPort;
        }
    }

    printf("udp port [%d, %d]\n", nMin, nMax);

    nMin = 65535;
    nMax = 0;
    for(nII = 0; nII < 65535 * 2; nII++)
    {
        TcpPortNotBind(&nBindPort);
        if(nBindPort < nMin)
        {
            nMin = nBindPort;
        }

        if(nBindPort > nMax)
        {
            nMax = nBindPort;
        }
    }

    printf("tcp port [%d, %d]\n", nMin, nMax);

    return 0;
}
