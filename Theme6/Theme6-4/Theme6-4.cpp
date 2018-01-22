#include <stdio.h>
#include <winsock.h>

int main(){
	WSADATA wsaData;
	SOCKET sock;
	SOCKADDR_IN addrin;
    HOSTENT *lpHostEnt;
    unistd int addr;
	int rtn_no;
	u_short port=50000;
	char szbuf[1024],ServerIP[16];

    printf("server ip address? ");
    gets(ServerIP);

    if( WSAStartup(MAKEWORD(2,2),&wsaData)){
        printf("WSAStartup error");
        WSACleanup();
        return -1;
    }

	sock = socket(AF_INET,SOCK_SOCK_STREAM,0);
	if(sock < 0){
		printf("socket error\n");
		WSACleanup();
		return -2;
	}

    lpHostEnt = gethostbyname(ServerIP);
    if(lpHostEnt == NULL){
        addr = inet_addr(ServerIP);
        lpHostEnt = gethostbyaddr((char*)&addr, 4, AF_INET);
    }
    if(lpHostEnt == NULL){
        printf("unknown server");
        closesocket(sock);
        WSACleanup();
        return -3;
    }


	memset(&addrin,0,sizeof(SOCKADDR_IN));
	addrin.sin_family = AF_INET;
	addrin.sin_port = htons(port);
    addrin.sin_addr.s_addr = *((u_long *)lpHostEnt->h_addr);

    if(connect(sock,(SOCKADDR *)&addrin,sizeof(addrin)) == SOCKET_ERROR){
        printf("connect Error\n");
        closesocket();
        WSACleanup();
        return -4;
    }else{
        printf("connect OK\n");
    }

    while(1){
        printf("message -> ");
        gets(szbuf);

        if(strcmp(buf,"c_stop") == 0){
            printf("server stop\n");
            break;
        }
        send(sock,szbuf,(int)strlen(szbuf),0);
        printf("Waiting message from server...\n");

        rtn_no = recv(sock,szbuf,sizeof(szbuf)-1,0);
        if(rtn_no == SOCKET_ERROR){
            printf("recv Error\n");
            break;
        }

        szbuf[rtn_no] = '\0';

        if(strcmp(szbuf,"s_stop")==0){
            printf("server shutdown the connection\n");
            break;
        }

        printf("recieve -> %s\n",szbuf);

    }
    shutdown(sock,SD_BOTH);
    closesocket(sock);
    WSACleanup();
    printf("stop application\n");

    return 0;
}
