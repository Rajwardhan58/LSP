//write a program which creates one child process,child process write something in unnamed pipe and parent process read the data fromm that pipe.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    int FD[2];
    int iRet =0;
    char Buffer[20]={'\n'};
    char *data="Here the data";
    pipe(FD);
    iRet=fork();
    if(iRet==0)
    {
        close(FD[0]);
        write(FD[1],data,strlen(data));
        exit(0);
    }
    else
    {
        close(FD[1]);
        read(FD[0],Buffer,sizeof(Buffer));
        printf("%s\n",Buffer);
        exit(0);
    }

    return 0;
}