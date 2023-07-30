#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int ret =0;
    int Exit_Status=0;
    int cpid=0; 
    ret = fork();
    if(ret==0)
    {
        execl("./Process3","NULL",NULL);
    }
    else
    {
        cpid=wait(&Exit_Status);
        printf("Inside Process2 with pid : %d\n",getpid());
    }
    return 0;
}