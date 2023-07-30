#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#define BUFFER_SIZE 1024

int main(int argc,char *argv[])
{
    int fd=0;
    char name[30]={'\n'};
    char Buffer[BUFFER_SIZE]={'\n'};
    int Count=0;
    int readCount=0;

    fd=open("Hello.txt", O_RDONLY);
    if(fd<0)
    {
        printf("cant open file\n");
        return -1;
    }
    while((readCount=read(fd,Buffer,sizeof(Buffer)))!=0)
    {
        int i=0;
        while(i!=readCount)
        {
            if(Buffer[i]>='A' && Buffer[i]<='Z') 
            {
                Count++;
            }  
            i++;
        }
        memset(Buffer,'\0',BUFFER_SIZE);
    }

    printf("Count of capital character in Hello.txt is %d\n",Count);
    return 0;
}