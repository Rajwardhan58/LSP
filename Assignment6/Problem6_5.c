//write a program which accept file name from user and offset,remove all the data from that offset.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#define BUFFER_SIZE 1024
int main(int argc,char *argv[])
{
    struct stat sobj;
    int fd=0,offset=atoi(argv[2]),retOff=0,readCount=0;
    char buffer[BUFFER_SIZE]={'\n'};
    if(argc!=3)
    {
        printf("Insufficient count\n");
        return -1;

    }
    fd=open(argv[1],O_RDWR);
    stat(argv[1],&sobj);

    if(sobj.st_size<offset)
    {
        printf("there is insufficient data\n");
        return -1;
    }

    //retOff=lseek(fd,offset,SEEK_SET);
    //printf("%d\n",retOff);

    if (truncate(argv[1] ,offset) == -1) {
        perror("truncate");
        close(fd);
        return 1;
    }

    close(fd);
    return 0;

}