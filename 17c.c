/*
============================================================================
Name : 17c.c
Author : Shatakshi Tiwari
Description : Write a program to execute ls -l | wc. USE fcntl.
Date: 8th Oct 2023
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>

int main()
{
        int fd[2];
        pipe(fd);

        if(!fork())
        {
                close(1);
                close(fd[0]);
                fcntl(fd[1],F_DUPFD,0);
                close(fd[1]);
                execlp("ls", "ls", "-l", (char*) NULL);
        }
        else
        {
                close(0);
                close(fd[1]);
                fcntl(fd[0],F_DUPFD,0);
                close(fd[0]);
                execlp("wc", "wc", (char*) NULL);
        }
}
