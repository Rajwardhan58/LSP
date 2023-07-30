//write a program which accept two files names from user and check whether contents of that two files are equal or not

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#define BUFFER_SIZE 1024


int main(int argc ,char *argv[])
{
    int firstFd=0,secFd=0,readCount1,readCount2;
    struct stat sobj1,sobj2;
    char buffer1[BUFFER_SIZE]={'\n'};
    char buffer2[BUFFER_SIZE]={'\n'};
    if(argc!=3)
    {
        printf("INsufficient arguments\n");
        return -1;
    }    

    firstFd = open(argv[1],O_RDONLY);
    secFd   = open(argv[2],O_RDONLY);

    if(firstFd<0 || secFd<0)
    {
        printf("cant open the file\n");
        return -1;
    }

    if(stat(argv[1],&sobj1)==0 && stat(argv[2],&sobj2)==0)
    {
        if(sobj1.st_size!=sobj2.st_size)
        {
            printf("file is not equal\n");
            return -1;
        }
    }

    while(1)
    {
        readCount1=read(firstFd,buffer1,BUFFER_SIZE);
        readCount2=read(secFd,buffer2,BUFFER_SIZE);

        if(readCount1 ==0 || readCount2==0)
        {
            break;
        }

        if(memcmp(buffer1,buffer2,readCount1)!=0)
        {
            printf("contents of file is not equal\n");
            return -1;
        }

        memset(buffer1,0,BUFFER_SIZE);
        memset(buffer2,0,BUFFER_SIZE);


    }

    printf("contents of file is equal\n");
    close(firstFd);
    close(secFd);

    return 0;
}