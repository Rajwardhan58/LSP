//write a program which is used to create unnamed pipe. Parent process creates new child process and both the processs will communicate with each other.


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


int main()
{
    int ArrFD[2];
    int iRet=0;
    char STR[]="Jay Ganesh";
    char Buffer[512];

    pipe(ArrFD);

    iRet=fork();

    if(iRet==0)     //child process to write data
    {
        close(ArrFD[0]);
        write(ArrFD[1],STR,strlen(STR));
        exit(0);
    }
    else            //parent process to write data
    {
        close(ArrFD[1]);
        read(ArrFD[0],Buffer,sizeof(Buffer));
        printf("Data from pipe is : %s\n",Buffer);
        exit(0);
    }

    return 0;
}