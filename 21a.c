/*
============================================================================
Name : 21a.c
Author : Shatakshi Tiwari
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
	int fd,fd2;
	char buff[80], buff2[80];
	fd=open("client", O_WRONLY);
	printf("Enter message from client:");
	scanf(" %[^\n]", buff);
	write(fd, &buff, sizeof(buff));
	fd2=open("server",O_RDONLY);
	read(fd2, &buff2, sizeof(buff2));
	printf("The text from server: %s\n", buff2);
}
