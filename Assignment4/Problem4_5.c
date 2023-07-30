//write a program which accept a file name and position from user and read 20 bytes from that position

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>
#define BUFFER_SIZE 20

int main(int argc,char *argv[])
{
    int fd=0;
    struct stat sobj;
    char buffer[BUFFER_SIZE]={'\n'};
    if(argc!=3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    fd=open(argv[1],O_RDONLY);
    if(fd<0)
    {
        printf("cant open file\n");
        return -1;
    }
    
    if(lseek(fd,atoi(argv[2]),0)==-1)
    {
        printf("cant find the position\n");
        return -1;
    }
    memset(buffer,0,BUFFER_SIZE);
    read(fd,buffer,BUFFER_SIZE);

    printf("%s\n",buffer);
    //stat(argv[1],&sobj);
    
    close(fd);
    return 0;
}