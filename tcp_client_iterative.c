#include <stdio.h>		/*header file include the input/output related functions*/ 
#include <stdlib.h>		/*defines four variable types, several macros, and various functions */
#include <errno.h>		/*defines the integer variable in the event of error*/
#include <string.h>		/* defines one variable type, one macro, and various functions*/
#include <netdb.h>		/* defines the netent structure members: char *n_name Official*/
#include <sys/types.h>		/*clock ID type in the clock and timer functions*/
#include <netinet/in.h>		/*declare buffers of the proper size */
#include <sys/socket.h>	/* access data arrays associated with a message header*/

#define SERVPORT 1233 	 /* server well-known port */
#define SERVIP “127.0.0.1” 	 /* server IP adress */
#define MAXDATASIZE 100 	/* max number of bytes we can get at once */

int main (int argc, char* argv[])
	{
	int sockfd, numbytes;
	char buf[MAXDATASIZE];
	struct sockaddr_in serv_addr; 		/* server address information */

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	serv_addr.sin_family = AF_INET; 		/* interpreted by host */
	serv_addr.sin_port = htons (SERVPORT);
	serv_addr.sin_addr.s_addr =inet_addr(SERVIP);
	bzero (&(serv_addr.sin_zero), 8); 		/* zero the rest of struct */

	connect (sockfd, (struct sockaddr*)&serv_addr, sizeof (struct sockaddr));
	numbytes = recv (sockfd, buf, MAXDATASIZE, 0);
		
	buf[numbytes] = ‘\0’;
	printf (“Received: %s”, buf);

	close (sockfd);

	return 0;
}   /* main function ends */
