#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define SERVPORT  1233 	 	/* server’s well-known port */
#define SERVIP  “127.0.0.1” 		/* server’s IP Addr*/
#define MAXDATASIZE 100 		/* max number of bytes to send */





int main (void)
{
	int sockfd, numbytes;
	char buf [MAXDATASIZE];
	struct sockaddr_in serv_addr; 		/* server address struct */

	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1 ) {
		    perror (“socket”); exit (1);
	   }
	serv_addr.sin_family = AF_INET; 		 /* address family*/
	serv_addr.sin_port = htons (SERVPORT);	 /* to short net byte order*/
	serv_addr.sin_addr.s_addr = inet_addr (SERVIP); /* server IP*/
	bzero (&(serv_addr.sin_zero), 8); 		/* zero rest of struct */

	




   while(1) {						 	/* always true */
		  sin_size = sizeof (struct sockaddr_in);

	    if ( sendto (sockfd, “Hello World! \n”, 14, 0, (struct sockaddr *) 
			   &serv_addr, &sin_size) == -1) {
			   perror ("recv");   
			   exit (1);
		      }
		    sleep (1);		
	}								 /* while loop ends here */
	return 0;
} 									/* main function ends here */
