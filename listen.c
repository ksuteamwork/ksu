#include<sys/types.h>
#include<sys/socket.h>
#include<netient/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORT		1234
#define MAXSOCKFD	10

int main(){
	int sockfd, newsockfd, is_connected[MAXSOCKFD],fd;
	struct sockaddr_in addr;
	int addr_len = sizeof(struct sockaddr_in);
	fd_set readfds;
	char buffer[256];
	char msg[] = "Welcome to server";

	if((socket(AF_INET, SOCK_STREAM, 0)) < 0){
	perror("socket");
	exit(1);
	}

bzero(&addr, sizeof(addr));
addr.sin_family = AF_INET;
addr.sin_port = htons(PORT);
addr.sin_addr.s_addr = htonl(INADDR_ANY);

	
}
