/*
============================================================================
Name : 16.c
Author : Shatakshi Tiwari
Description : Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 25th , Aug 2023
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void)
{
	char buff[80] , buff1[80] ;
	int fd1[2]  , fd2[2] ;

	pipe(fd1);
	pipe(fd2);

	if(!fork())
	{
		close(fd1[0]);//closing the read end of 1st pipe
                printf("Enter message to the parent :");
		scanf("%[^\n]" , buff);
		write(fd1[1] , buff , sizeof(buff));
		close(fd2[1]); // closing the write end of the 2nd pipe 
	        read(fd2[0]  , buff1 , sizeof(buff1)) ;
	       printf("Message from parent : %s\n" , buff1 );
	}
 else {
              close(fd1[1]);//closing the write  end of 1st pipe
	      read(fd1[0] , buff , sizeof(buff));
                printf("Message from the child : %s\n",buff);
		close(fd2[0]); //closing the read end of the 2nd pipe
               printf("Enter the message from the child:" );
	       scanf(" %[^\n]" , buff1);
	       write(fd2[1] , buff1 , sizeof(buff1));
        }
wait(0);
}
