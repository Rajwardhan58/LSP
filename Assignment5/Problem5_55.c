//write a program which accept file name from user which contains data of all files . we have to create all file again.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#define BUFFER_SIZE

int main(int argc,char *argv[])
{
    DIR *dp,*newDp;
    char path[50]={'\0'};
    char newPath[50]={'\0'};

    struct dirent *entry;
    struct stat sobj;
    int fd=0,newFd=0;
    int readCount=0;
    char *buffer;
    //char path[20]={'\0'};
    if(argc!=2)
    {
        printf("Insufficient count\n");
        return -1;
    }

    if((dp=opendir("test1"))==NULL)
    {    
        printf("cant open directory\n");
        return -1;   
    }
    if((newDp=opendir("test2"))==NULL)
    {
        printf("cant open directory\n");
        return -1;
    }

    fd=open(argv[1],O_RDONLY);

    while((entry=readdir(dp))!=NULL)
    {
        
        sprintf(path,"test1/%s",entry->d_name);
        stat(path,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
        int size=(int)sobj.st_size;
        printf("%d\n",size);
        buffer=(char *)malloc(size*sizeof(char));
        sprintf(newPath,"test2/%s",entry->d_name);
        newFd=creat(newPath,0777);
        if(newFd<0)
        {
            free(buffer);
            continue;
        }
        readCount=read(fd,buffer,size);
        printf("%d\n",readCount);
        write(newFd,buffer,readCount);
        free(buffer);
        }
    }

    close(newFd);
    close(fd);
    closedir(newDp);
    closedir(dp);

    return 0;
}