/*
============================================================================
Name : 20r.c
Author : Shatakshi Tiwari
Description : Write two programs so that both can communicate by FIFO -Use one way communication 
Date: 8th Oct 2023 
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
	int fd;
	char buff[80];
	fd=open("myfifo",O_RDONLY);
	read(fd, &buff, sizeof(buff));
	printf("The text from FIFO file: %s\n", buff);
}
