#include "sharedFile.h"
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#define BUFFER_SIZE 1024

int CompareFile(char *file1,char *file2)
{
    int firstFd=0,secFd=0,readCount1=0,readCount2=0,flag=0;

    firstFd = open(file1,O_RDONLY);
    secFd   = open(file2,O_RDONLY);
    char buffer1[BUFFER_SIZE]={'\0'};
    char buffer2[BUFFER_SIZE]={'\0'};

    struct stat sobj1,sobj2;
    if(firstFd<0 || secFd<0)
    {
        return -1;
    }
    if(stat(file1,&sobj1)==0 && stat(file2,&sobj2)==0)
    {
        if(sobj1.st_size!=sobj2.st_size)
        {
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
            flag=1;
            break;
        }

        memset(buffer1,0,BUFFER_SIZE);
        memset(buffer2,0,BUFFER_SIZE);

    }
    close(firstFd);
    close(secFd);
    if(flag)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
