//write a program which create three level process hierarchy where process 1 creates process 2 and it internaly creates process 3

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
        execl("./Process2","NULL",NULL);
    }
    else
    {
        cpid=wait(&Exit_Status);
        printf("Inside Process1 with pid : %d\n",getpid());
    }
    return 0;
}