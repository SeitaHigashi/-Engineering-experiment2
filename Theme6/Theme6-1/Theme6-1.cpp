#include <stdio.h>
#include <winsock.h>

int main()
{
	WSADATA wsaData;
	SOCKET sock;
	SOCKADDR_IN addrin;
	SOCKADDR_IN from;
	int fromlen;
	int rtn_no;
	u_short port=50000;
	char buf[256];

	if(WSAStartup(MAKEWORD(1,1),&wsaData)!=0){
		printf("WSAStartup Error\n");
		return -1;
	}

	sock= socket(AF_INET,SOCK_DGRAM,0);
	if(sock<0){
		printf("socket failure\n");
		WSACleanup();
		return -2;
	}

	memset(&addrin,0,sizeof(addrin));
	addrin.sin_port=htons(port);
	addrin.sin_family=AF_INET;
	addrin.sin_addr.s_addr=htonl(INADDR_ANY);

	rtn_no=bind(sock,(LPSOCKADDR)&addrin,(int)sizeof(addrin));
	if(rtn_no == SOCKET_ERROR){
		printf("bind error\n");
		closesocket(sock);
		WSACleanup();
		return -3;
	}
	while(1){
		fromlen = (int)sizeof(from);
		rtn_no=recvfrom(sock,buf,(int)sizeof(buf)-1,0,(SOCKADDR *)&from,&fromlen);
		if(rtn_no==SOCKET_ERROR){
			printf("recvform error\n");
			closesocket(sock);
			WSACleanup();
			return -4;
		}
		buf[rtn_no]='\0';

		if(strcmp(buf,"s_stop")==0){
			printf("server stop\n");
			break;
		}
		printf("%s -> %s\n",inet_ntoa(from.sin_addr),buf);

	}
	closesocket(sock);
	WSACleanup();
	printf("Stop\n");

	return 0;
}
