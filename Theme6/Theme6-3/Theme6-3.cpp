#include <stdio.h>
#include <winsock2.h>

int main()
{
	WSADATA wsaData;
	SOCKET sock,listen_s;
	SOCKADDR_IN addrin;
	SOCKADDR_IN from;
	int fromlen;
	int rtn_no;
	u_short port=60000;
	char szBuf[1024];

	if(WSAStartup(MAKEWORD(2,2),&wsaData)){
		printf("WSAStartup Error\n");
		WSACleanup();
		return -1;
	}

	listen_s = socket(AF_INET,SOCK_STREAM,0);
	if(listen_s<0){
		printf("socket failure\n");
		WSACleanup();
		return -2;
	}else{
		printf("socket open\n");
	}
	 
	memset(&addrin,0,sizeof(SOCKADDR_IN));
	addrin.sin_family=AF_INET;
	addrin.sin_port=htons(port);
	addrin.sin_addr.s_addr=INADDR_ANY;

	if(bind(listen_s,(struct sockaddr *)&addrin,sizeof(addrin))== SOCKET_ERROR){
		printf("bind error\n");
		closesocket(listen_s);
		WSACleanup();
		return -3;
	}else{
		printf("bind success\n");
	}

	if(listen(listen_s,0) == SOCKET_ERROR){
		printf("listen error\n");
		closesocket(listen_s);
		WSACleanup();
		return -4;
	}else{
		printf("listen success\n");
		printf("accept waiting...\n");
	}
	fromlen = (int)sizeof(from);
	sock = accept(listen_s,(SOCKADDR *)&from,&fromlen);
	if(sock == INVALID_SOCKET){
		printf("accept error");
		closesocket(listen_s);
		WSACleanup();
		return -5;
	}else{
		printf("%s connect\n",inet_ntoa(from.sin_addr));
		printf("accept success\n\n");
	}

	closesocket(listen_s);

	while(1){
		printf("Waiting message from client...\n");
		rtn_no = recv(sock, szBuf, sizeof(szBuf)-1,0);

		if(rtn_no==SOCKET_ERROR){
			printf("recv error\n");
			break;
		}

		szBuf[rtn_no]='\0';
		if(strcmp(szBuf,"c_stop")==0){
			printf("client shutdown the connection\n");
			break;
		}
		printf("recieve -> %s\n",szBuf);
		printf("message -> ");
		gets(szBuf);
		if(strcmp(szBuf,"s_stop")==0){
			send(sock,szBuf,(int)strlen(szBuf),0);
			break;
		}
		send(sock, szBuf,(int)strlen(szBuf),0);
	}
	shutdown(sock,SD_BOTH);
	closesocket(sock);
	WSACleanup();
	printf("Stop application\n");

	return 0;
}
