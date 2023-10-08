/*
============================================================================
Name : 19e.c
Author : Shatakshi Tiwari
Description : Create a FIFO file by mkfifo library function.
Date: 25th , Aug 2023
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(void){
	int f = mkfifo("myfifo", 0666);
	if(f<0){
		perror("Failed:");
	}
	else
		printf("File Created.\n");
	close(f);
}
