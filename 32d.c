/*
============================================================================
Name : 32d.c
Author : Shatakshi Tiwari
Description : Write a program to implement semaphore to protect any critical section.
d. remove the created semaphore
Date: 25th , Aug 2023
============================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <unistd.h>

int main()
{	
	int semid;
	printf("Enter the ID of Semaphore you want to remove :\n");
	scanf("%d",&semid);

	int ret = semctl(semid,0,IPC_RMID);
	if(ret==-1)
	{
		perror("SEMCTL ERROR");
		return -1;
	}
	else
		printf("Semaphore with ID %d is removed successfully!!!\n",semid);
	return 0;
}
