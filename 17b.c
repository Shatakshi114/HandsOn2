/*
============================================================================
Name : 17b.c
Author : Shatakshi Tiwari
Description : Write a program to execute ls -l | wc. USE dup2.
Date: 8th Oct 2023
============================================================================
*/



#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
        int fd[2];
        pipe(fd);

        if(!fork())
        {
                close(1);
                close(fd[0]);
                dup2(fd[1],1);
                execlp("ls", "ls", "-l", (char*) NULL);
        }
        else
        {
                close(0);
                close(fd[1]);
                dup2(fd[0],0);
                execlp("wc", "wc", (char*) NULL);
        }
}
