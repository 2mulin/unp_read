#include "unp.h"
#include <time.h>

int main(int argc, char **argv)
{
	int					listenFd;
	struct sockaddr_in	servaddr;
	time_t ticks;

	listenFd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(33333);

	bind(listenFd, (SA*)&servaddr, sizeof(servaddr));
	listen(listenFd, LISTENQ);
	
	int connfd = 0;
	for(;;)
	{
		connfd = accept(listenFd, NULL, NULL);
		ticks = time(nullptr);
		char buf[4096] = {0};
		snprintf(buf, sizeof(buf), "time: %.24s\r\n", ctime(&ticks));
		write(connfd, buf, strlen(buf));
		close(connfd);
	}
	return 0;
}
