#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int p=0;
    int cpid=0;
    int exitStatus=0;

    p=fork();
    if(p==0)
    {
        execl("./Process","NULL",NULL);
    }
    else
    {
        cpid=wait(&exitStatus);
        printf("child process having pid %d with exit status %d\n",cpid,exitStatus);
    }
    return 0;
}