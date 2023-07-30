//Write a program which accept file name from user and read whole file.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#define BUFFER_SIZE 1024

int main(int argc,char *argv[])
{
    int fd=0;
    char buffer[BUFFER_SIZE]={'\n'};
    int readCount=0;
    if(argc!=2)
    {
        printf("Usage : Name_Of_Executable_File Name_Of_File\n");
		return -1;
    }

    fd=open(argv[1],O_RDONLY);
    if(fd<0)
    {
        printf("Can't open file\n");
		return -1; 
    }
    memset(buffer,0,sizeof(buffer));
    while((readCount=read(fd,buffer,sizeof(buffer)))!=0)
    {
        printf("%s",buffer);
        memset(buffer,0,sizeof(buffer));

    }

    close(fd);

    return 0;
}