//write a program in which process waits till its child process terminates.

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int ret = 0;
    int cpid = 0;
    int Exit_Status=0;
    ret = fork();

    if(ret == 0)
    {
        execl("./child","NULL",NULL);
    }
    else
    {
        printf("Parent is running with PID : %d\n",getpid());
        cpid=wait(&Exit_Status);
        printf("child process having pid %d with exit status %d\n",cpid,Exit_Status);
    }
    return 0;
}