#include <stdio.h>
#include <winsock2.h>

int main()
{
	WSADATA wsaData;
	SOCKET sock;
	SOCKADDR_IN addrin;
	HOSTENT *lpHostEnt;
	unsigned int addr;
	int rtn_no;
	u_short port=60000;
	char szBuf[1024],ServerIP[1024];

	printf("server ip adress?");
	gets(ServerIP);

	if(WSAStartup(MAKEWORD(2,2),&wsaData)){
		printf("WSAStartup Error\n");
		WSACleanup();
		return -1;
	}

	sock= socket(AF_INET,SOCK_STREAM,0);
	if(sock<0){
		printf("socket error\n");
		WSACleanup();
		return -2;
	}

	lpHostEnt = gethostbyname(ServerIP);
	if(lpHostEnt == NULL){
		addr = inet_addr(ServerIP);
		lpHostEnt = gethostbyaddr((char *)&addr,4,AF_INET);
	}
	if(lpHostEnt == NULL){
			printf("unknown server\n");
			closesocket(sock);
			WSACleanup();
			return -3;
	}

	memset(&addrin,0,sizeof(SOCKADDR_IN));
	addrin.sin_family=lpHostEnt->h_addrtype;
	addrin.sin_port=htons(port);
	addrin.sin_addr.s_addr= *((u_long *)lpHostEnt->h_addr);

	if(connect(sock,(SOCKADDR *)&addrin,sizeof(addrin)) == SOCKET_ERROR){
		printf("connect error\n");
		closesocket(sock);
		WSACleanup();
		return -4;
	}else{
		printf("connect OK\n");
	}

	while(1){
		printf("message -> ");
		gets(szBuf);
		if(strcmp(szBuf,"c_stop")==0){
			send(sock,szBuf,(int)strlen(szBuf),0);
			break;
		}
		send(sock,szBuf,(int)strlen(szBuf),0);
		printf("Waiting message from server...\n");
		rtn_no = recv(sock,szBuf,sizeof(szBuf)-1,0);
		if(rtn_no == SOCKET_ERROR){
			printf("recv error\n");
			break;
		}
		szBuf[rtn_no]='\0';

		if(strcmp(szBuf,"s_stop")==0){
			printf("server shutdown the connection\n");
			break;
		}
		printf("recieve -> %s\n",szBuf);
	}
	shutdown(sock,SD_BOTH);
	closesocket(sock);
	WSACleanup();
	printf("Stop application\n");

	return 0;
}
