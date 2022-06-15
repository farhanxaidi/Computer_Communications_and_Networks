#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>			

#define PORT 1233   			/* my well-known port */
#define MAXDATASIZE 100   		/* max data to receive in one pkt*/





int main (void)
{
	int sockfd; 						/* listen on sockfd */
	struct sockaddr_in my_addr; 			/* server address struct */
	struct sockaddr_in their_addr; 			/* client addr struct */
	int sin_size; 						/* address struct size */
	int numbytes; 			   			/* number of bytes captured*/
	char buf [MAXDATASIZE]; 
	

	if ((sockfd = socket (AF_INET, SOCK_DGRAM, 0)) == -1) {
		    perror("socket");
		    exit(1);
	     } 	





my_addr.sin_family = AF_INET; 				/* address family*/
my_addr.sin_port = htons (MYPORT); 			/* convert to short, network byte order */
my_addr.sin_addr.s_addr =(INADDR_ANY); 		/* automatically fill with my IP */ 	
bzero (&(my_addr.sin_zero), 8); 				/* zero rest of struct */

if (bind (sockfd, (struct sockaddr *)&my_addr, sizeof (struct sockaddr) ) == -1) {
		perror("bind");
		exit(1);
		}







  while(1) { 						/* always true */
	  sin_size = sizeof (struct sockaddr_in);

	  if ( (numbytes = recvfrom (sockfd, buf, MAXDATASIZE-1, 0,
			(struct sockaddr *) &their_addr, &sin_size) ) == -1) {
			perror ("recv");   exit (1);
			}
		 buf [numbytes] = '\0';
		 printf ("Server received: %s \n\n", buf);
		 }						 /* while loop ends here */
	return 0;
} 	