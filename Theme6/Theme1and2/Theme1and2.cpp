#include <stdio.h>
#include <winsock.h>

int main()
{
	WSADATA wsaData;
	SOCKET sock;
	SOCKADDR_IN addrin;
	SOCKADDR_IN from;
	HOSTENT *lpHostEnt;
	unsigned int addr;
	int fromlen;
	int rtn_no;
	u_short port=50000;
	char buf[1024],ServerIP[16];
	BOOLEAN serverFlag=false;

	printf("Server([Y]es/[N]o)?\n");
	scanf("%s%*c",buf);
	serverFlag=(buf[0]=='Y')?true:false;
	if(serverFlag==false){
		printf("server ip adress?");
		gets(ServerIP);
	}


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
		addrin.sin_family=AF_INET;
		addrin.sin_port=htons(port);

	if(serverFlag==false){
		lpHostEnt = gethostbyname(ServerIP);
		if(lpHostEnt == NULL){
			addr = inet_addr(ServerIP);
			lpHostEnt = gethostbyaddr((char *)&addr,4,AF_INET);
			if(lpHostEnt == NULL){
				printf("unknown server\n");
				return -3;
			}
		}

		memcpy(&(addrin.sin_addr),lpHostEnt->h_addr_list[0],lpHostEnt->h_length);

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
	}else{

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
	}
	closesocket(sock);
	WSACleanup();
	printf("Stop\n");

	return 0;
}
