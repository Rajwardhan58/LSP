//write a program which accept directory name from user and copy first 10 bytes from all regular files into newly created file Demo.txt

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>
#define BUFFER_SIZE 10

int main(int argc,char *argv[])
{
    DIR *dp;
    struct dirent *entry;
    int newFd=0,fd=0;
    int readCount=0;
    char buffer[BUFFER_SIZE];
    if(argc!=2)
    {
        printf("insufficient arguments\n");
        return -1;
    }

    dp=opendir(argv[1]);

    if(dp==NULL)
    {
        printf("unable to open directory\n");
        return -1;
    }

    newFd=creat("Demo.txt",0777);
    memset(buffer,0,BUFFER_SIZE);
    while((entry=readdir(dp))!=NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) 
        {
           continue; 
        }

       // sprintf(sourceDir,"%s/%s",argv[1],entry->d_name);
        fd=open(entry->d_name,O_RDONLY);
        readCount=read(fd,buffer,BUFFER_SIZE);
        write(newFd,buffer,strlen(buffer));
        
        memset(buffer,0,BUFFER_SIZE);
        
    }
    close(fd);
    close(newFd);
    closedir(dp);
    return 0;
}