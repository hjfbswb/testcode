#include <stdio.h>

#ifdef _MSC_VER
#pragma comment( lib, "ws2_32.lib")

#include <winsock2.h>
#include <Ws2tcpip.h>

typedef int socklen_t;
#define inet_ntop InetNtop
#define sleep(n) Sleep((n) * 1000)
#define LastNetError	 WSAGetLastError()
#else
#include <errno.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef int SOCKET;
#define closesocket close
#define LastNetError errno
#endif

#ifdef _MSC_VER
int dupsocket(SOCKET hOld, SOCKET * phNew)
{
	BOOL bRet = FALSE;
	HANDLE hNew = NULL;

	bRet = DuplicateHandle(GetCurrentProcess(), (HANDLE)hOld, GetCurrentProcess(), (HANDLE*)phNew, 0, FALSE, DUPLICATE_SAME_ACCESS);
	if(0 == bRet)
	{
		printf("dup handle failed %d, errno %d\n", bRet, GetLastError());
		return -1;
	}

	return 0;
}

int Init()
{
	WSADATA tWsaData;

	WSAStartup(MAKEWORD(2, 2), &tWsaData);

	return 0;
};
void Uninit()
{
	WSACleanup();
}
#else
int dupsocket(SOCKET hOld, SOCKET * phNew)
{
	int nRet = 0;

	nRet = dup(hOld);
	if (nRet < 0)
	{
		printf("dup failed %d, errno %d\n", nRet, errno);
		return -1;
	}

	*phNew = nRet;

	return 0;
}
int Init()
{
	return 0;
}
void Uninit()
{
}
#endif

int main(int argc, char ** argv)
{
    int nRet = 0;
    const char * szRet = NULL;
	SOCKET nSrvSock = 0;
    int nCltSock = 0;
    int nDupSock = 0;
    struct sockaddr_in tAddr = {AF_INET};
    socklen_t nAddrLen = 0;
    char szIPBuf[64] = {0};
    int nListenPort = 0;

    if(2 != argc)
    {
        printf("usage: %s port\n", argv[0]);
        return 1;
    }

    nListenPort = atoi(argv[1]);
    printf("listen port %d\n", nListenPort);

	Init();

	nSrvSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(nSrvSock < 0)
	{
		return 1;
	}

    tAddr.sin_family = AF_INET;
    tAddr.sin_addr.s_addr = INADDR_ANY;
    tAddr.sin_port = htons(nListenPort);

	nRet = bind(nSrvSock, (struct sockaddr*)&tAddr, sizeof(tAddr));
    if(0 != nRet)
    {
        printf("bind failed %d, errno %d\n", nRet, LastNetError);
        return 2;
    }

    nRet = listen(nSrvSock, 5);
    if(nRet < 0)
    {
        return 3;
    }

    nAddrLen = sizeof(tAddr);
    nCltSock = accept(nSrvSock, (struct sockaddr*)&tAddr, &nAddrLen);
    if(nCltSock < 0)
    {
        return 4;
    }

    szRet = inet_ntop(AF_INET, (void *)&tAddr.sin_addr, szIPBuf, sizeof(szIPBuf));
    if(NULL == szRet)
    {
        return 4;
    }
    
    printf("accept from {%s:%d}\n", szIPBuf, ntohs(tAddr.sin_port));

    nRet = dupsocket(nCltSock, &nDupSock);
    if(nRet < 0)
    {
		printf("dup socket failed %d\n", nRet);
        return 5;
    }

    printf("clt sock %d, dup sock %d\n", nCltSock, nDupSock);
	closesocket(nCltSock);
    printf("close clt sock %d\n", nCltSock);

    while(1)
    {
        sleep(1);

        nRet = send(nDupSock, "hello\n", 6, 0);
        if(nRet < 0)
        {
			printf("send failed %d, errno %d\n", nRet, LastNetError);
            break;
        }
    }

	closesocket(nDupSock);
	printf("close dup sock %d\n", nDupSock);
    
	Uninit();
	
	return 0;
}

