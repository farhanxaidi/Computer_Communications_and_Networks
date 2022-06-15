#include <stdio.h>		/*header file include the input/output related functions*/ 
#include <stdlib.h>		/*defines four variable types, several macros, and various functions */
#include <unistd.h>		/*ymbolic constants and types, and declares miscellaneous functions*/
#include <string.h>		/* defines one variable type, one macro, and various functions*/
#include <sys/socket.h> /* defines macro to gain access to data arrays associated with message header*/ 
#include <netinet/in.h>		/*declare buffers of the proper size */
#include <arpa/inet.h>		/*header makes available the type in_port_t and the type in_addr_t as 						defined in the description */

#define MYPORT 1233   /* my well-known port */
#define BACKLOG 10 	 /* length of pending connections queue */

int main(void)
	{
	int sockfd, new_fd; 	/* listen on sockfd */			/* new connection on new_fd */

	struct sockaddr_in  my_addr; 		/* server address */
	struct sockaddr_in  cli_addr; 		/* client addr */
	int sin_size; 				/* address size */

	sockfd = socket(AF_INET, SOCK_STREAM, 0); 	/*connection-based protocol*/

	my_addr.sin_family = AF_INET; 	/*address family that is used for the socket you're creating*/
	my_addr.sin_port = htons(MYPORT); 	/* convert to short, net byte order */
	my_addr.sin_addr.s_addr = htonl(INADDR_ANY); 	/* auto fill with my IP */
	bzero(&(my_addr.sin_zero), 8); 		/* zero the rest of the struct */
 				
	bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr));

	listen(sockfd, BACKLOG);

	while(1) { 	/* main accept() loop ; always true*/
		sin_size = sizeof(struct sockaddr_in);

		new_fd = accept(sockfd, (struct sockaddr*) &cli_addr, &sin_size);
		printf("server: connection from %s\n", inet_ntoa(cli_addr.sin_addr) );

		send(new_fd, "Hello, world!\n", 14, 0);

		close(new_fd);
	} 	/* while loop ends here */

	return 0;
} 		/* main function ends here */

