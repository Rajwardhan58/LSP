//write a program which accept two file names from user and copy the contents of an existing file into newly created file

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#define BUFFER_SIZE 1024
int main(int argc,char *argv[])
{

    int startFd=0,destFd=0,readCount=0;
    char buffer[BUFFER_SIZE]={'\n'};

    if(argc!=3)
    {
        printf("Usage : Name_Of_Executable_File Name_Of_Existing_File Name_Of_New_File\n");
		return -1;
    }

    startFd=open(argv[1],O_RDONLY);

    if(startFd<0)
    {
        printf("unable to open file\n");
        return -1;
    }

    destFd=creat(argv[2],0777);
    memset(buffer,0,sizeof(buffer));
    while((readCount=read(startFd,buffer,sizeof(buffer)))!=0)
    {
        write(destFd,buffer,sizeof(buffer));
        memset(buffer,0,sizeof(buffer));
    }

        close(destFd);
        close(startFd);

    return 0;
}