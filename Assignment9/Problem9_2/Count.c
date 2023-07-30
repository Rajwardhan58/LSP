#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int p1=0,p2=0;
    int cpid1=0,cpid2=0;
    int exitStatus1=0,exitStatus2=0;

    p1=fork();
    if(p1==0)
    {
        execl("./Process1","NULL",NULL);
    }
    else
    {
        cpid1=wait(&exitStatus1);
    }
    p2=fork();
    if(p2==0)
    {
        execl("./Process2","NULL",NULL);
    }
    else
    {
        cpid2=wait(&exitStatus2);
    }
    return 0;
}