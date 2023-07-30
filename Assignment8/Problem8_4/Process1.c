
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int p4=0,p2=0;
    int cpid2=0,cpid3=0;
    int exitStatus3=0,exitStatus2=0;

    p2=fork();
    if(p2==0)
    {
        execl("./Process2","NULL",NULL);
    }
    else
    {
        cpid2=wait(&exitStatus2);
        printf("child process having pid %d with exit status %d\n",cpid2,exitStatus2);
    }

    p3=fork();
    if(p3==0)
    {
        execl("./Process3","NULL",NULL);
    }
    else
    {
        cpid3=wait(&exitStatus3);
        printf("child process having pid %d with exit status %d\n",cpid3,exitStatus3);
    }

    printf("Parent Process terminates\n");
    return 0;
}