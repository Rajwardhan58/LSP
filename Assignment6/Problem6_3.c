//write a program which accept directory name and file name from user and create that file in directory

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc,char *argv[])
{
    DIR *dp;

    int newFd=0;
    char fileName[20]={'\0'};
    
    if(argc!=3)
    {
        printf("Insufficient count\n");
        return -1;
    }

    dp=opendir(argv[1]);
    if(dp==NULL)
    {
        printf("Unable to open file\n");
        return -1;
    }

    sprintf(fileName,"%s/%s",argv[1],argv[2]);
    newFd=creat(fileName,0777);
    if(newFd<0)
    {
        printf("cant create the file\n");
        return -1;
    }

    printf("file created successfully\n");
    close(newFd);
    closedir(dp);
    return 0;
}