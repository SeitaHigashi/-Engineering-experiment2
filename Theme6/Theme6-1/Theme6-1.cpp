#include <stdio.h>
#if defined WIN32
#include <winsock.h>
#else
#define closesocket close
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

int main(){
	WSADATA wsaData;
	SOCKET sock;
	SOCKADDR_IN addrin;
	SOCKADDR_IN from;
	int fromlen;
	int rtn_no;
	u_short port=50000;
	char szbuf[1024];

	if (WSAStartup(MAKEWORD(1,1),&wsaData) != 0){
		printf("WSAStartup Error\n");
		return -1;
	}

	listen_s = socket(AF_INET,SOCK_STREAM,0);
	if(listen_s < 0){
		printf("socket error\n");
		WSACleanup();
		return -2;
	}else{
        printf("socket open");
    }

	memset(&addrin,0,sizeof(SOCKADDR_IN));
	addrin.sin_family = AF_INET;
	addrin.sin_port = htons(port);
	addrin.sin_addr.s_addr = INADDR_ANY;

	if(bind(sock,(LPSOCKADDR)&addrin,(int)sizeof(addrin))== SOCKET_ERROR){
        printf("bind Error\n");
        closesocket(listen_s);
        WSACleanup();
        return -3;
    }else{
        printf("bind success\n");
    }

    if(listen(listen_s,0) == SOCKET_ERROR){
        printf("listen Error\n");
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
        rtn_no = recv(sock,szbuf,sizeof(szbuf) - 1,0);
        if(rtn_no == SOCKET_ERROR){
            printf("recv error");
            break;
        }
        szbuf[rtn_no] = '\0';

        if(strcmp(szbuf,"c_stop") == 0){
            printf("client shutdown the connection\n");
            break;
        }
        printf("recieve -> %s\n",szbuf);
        printf("message -> ");
        gets(szbuf);
        if(strcmp(szbuf,"s_stop") == 0){
            send(sock,szbuf,(int)strlen(szbuf),0);
            break;
        }
        send(sock,szbuf,(int)strlen(szbuf),0);
    }
    shutdown(sock,SD_BOTH);
    closesocket(sock);
    WSACleanup();
    printf("stop application\n");

    return 0;
}
