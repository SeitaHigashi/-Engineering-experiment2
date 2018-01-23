#include <stdio.h>
#include <winsock.h>

int main()
{
	WSADATA wsaData;
	SOCKET sock;
	SOCKADDR_IN addrin;
	HOSTENT *lpHostEnt;
	unsigned int addr;
	int rtn_no;
	u_short port=50000;
	char buf[1024],ServerIP[16];

	printf("server ip adress?");
	gets(ServerIP);

	rtn_no=WSAStartup(MAKEWORD(1,1),&wsaData);
	if(rtn_no!=0){
		printf("WSAStartup error\n");
		return -1;
	}
	sock= socket(AF_INET,SOCK_DGRAM,0);
	if(sock<0){
		printf("socket failure\n");
		WSACleanup();
		return -2;
	}
	lpHostEnt = gethostbyname(ServerIP);
	if(lpHostEnt == NULL){
		addr = inet_addr(ServerIP);
		lpHostEnt = gethostbyaddr((char *)&addr,4,AF_INET);
		if(lpHostEnt == NULL){
			printf("unknown server\n");
			return -3;
		}
	}

	memset(&addrin,0,sizeof(addrin));
	memcpy(&(addrin.sin_addr),lpHostEnt->h_addr_list[0],lpHostEnt->h_length);
	addrin.sin_port=htons(port);
	addrin.sin_family=AF_INET;

	while(1){
		printf("message -> ");
		gets(buf);
		rtn_no = sendto(sock,buf,(int)strlen(buf)+1,0,(LPSOCKADDR)&addrin,sizeof(addrin));
		if(rtn_no != (int)strlen(buf)+1){
			printf("send error\n");
			closesocket(sock);
			WSACleanup();
			return -4;
		}
		if(strcmp(buf,"c_stop")==0){
			printf("stop\n");
			break;
		}

	}
	closesocket(sock);
	WSACleanup();
	return 0;
}
