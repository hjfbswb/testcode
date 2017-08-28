#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

static int _SendMulticastMsg(const void* szData, const int nDataSize, 
                            const char * szDstIP, const int nDstPort)
{
    int nRet = 0;
    int nSock = -1;
    int nSended = 0;
    struct sockaddr_in tDstAddr = {0};

    do
    {
        nSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if(nSock < 0)
        {
            printf("socket() failed\n");
            nRet = 1;
            break;
        }

        tDstAddr.sin_family = AF_INET;
        tDstAddr.sin_addr.s_addr = inet_addr(szDstIP);
        tDstAddr.sin_port = htons(nDstPort);

        nSended = sendto(nSock, szData, nDataSize, 0, 
                            (struct sockaddr *)&tDstAddr, sizeof(tDstAddr));
        if(nSended < 0)
        {
            printf("sendto() failed\n");
            nRet = 2;
            break;
        }

        nRet = 0;
    }while(0);

    if(nSock >= 0)
    {
        close(nSock);
    }

    return nRet;
}

int main(int argc, char ** argv)
{
    char * szDstIP = NULL;
    int nDstPort = 0;
    
    if(3 != argc)
    {
        printf("./s dst_ip dst_port\n");
        return 1;
    }

    szDstIP = argv[1];
    nDstPort = atoi(argv[2]);

    printf("dst {%s:%d}\n", szDstIP, nDstPort);

    if(0 != _SendMulticastMsg("hello", 6, szDstIP, nDstPort))
    {
        printf("_SendMulticastMsg() failed\n");
    }
    else
    {
        printf("_SendMulticastMsg() ok\n");
    }
    
    return 0;
}

