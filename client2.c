#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>


#define PORT		80
#define SERVER_IP	"192.168.128.95"

int main(){
	int s,len;
	struct sockaddr_in addr;
	char buffer[1024];
	char var[]="GET /2.txt HTTP/1.1\r\n"
		   "User-Agent:Wget/1.15.1(linux-gnu)\r\n"
		   "Accept:*/*\r\n"
		   "Accept-Encoding: indentity\r\n"
		   "Host: 192.168.128.65\r\n"
		   "Cpnnection: Keep-Alive\r\n\r\n";

	FILE*fd;

	if((s = socket(AF_INET, SOCK_STREAM, 0))<0){
		perror("socket");
		exit(1);
	}

	bzero(&addr,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = inet_addr(SERVER_IP);

	if(connect(s, (struct sockaddr*)&addr, sizeof(addr)) < 0){
		perror("connect");
		exit(1);
	}

	sprintf(buffer,"%s" ,var);
        write(s, buffer,sizeof(buffer));
	bzero(buffer, sizeof(buffer));

	recv(s, buffer, sizeof(buffer), 0);
	printf("%s\n", buffer);
	bzero(buffer, sizeof(buffer));
	fd = fopen("a.txt","w");

	//int len = recv(s,buffer,sizeof(buffer),0);
	while(len = recv(s,buffer,sizeof(buffer),0) > 0){
	fprintf(fd,"%s", buffer);
	bzero(buffer, sizeof(buffer));
	}
}
