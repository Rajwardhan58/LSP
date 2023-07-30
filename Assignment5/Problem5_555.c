//write a program which accept file name from user which contains data of all files . we have to create all file again.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#define BUFFER_SIZE 1024;

struct FileInfo
{
    char name[20];
    char mode[20];
    int inode;
    int linkNum;
    int devId;
    int size;
};

int main(int argc,char *argv[])
{
    int infoFileFd=0,dataFileFd=0,bytesRead=0,newFd=0,readCount=0;
    DIR *dp;
    char *buffer;
    char nameBuf[20]={'\0'};
    char path[50]={'\0'};
    struct dirent *entry;
    if(argc!=2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    infoFileFd=open("InfoFile.txt",O_RDONLY);
    if(infoFileFd<0)
    {
        printf("can't open file info\n");
        return -1;
    }

    dataFileFd=open(argv[1],O_RDONLY);
    if(dataFileFd<0)
    {
        printf("can't open file info\n");
        return -1;
    }

    dp=opendir("newDir");
    if(dp==NULL)
    {
        mkdir("newDir",0777);
    }
    struct FileInfo fobj;
    while((bytesRead=read(infoFileFd,&fobj,sizeof(fobj)))!=0)
    {
        
        //bytesRead=read(infoFileFd,&fobj,sizeof(fobj));
        strcpy(nameBuf,fobj.name);
        int size=(int)fobj.size;
        printf("%s : %d\n",fobj.name,size);
       sprintf(path,"newDir/%s",nameBuf);

        newFd=creat(path,0777);

       buffer=(char *)malloc(size*sizeof(char));

       readCount=read(dataFileFd,buffer,size);
       write(newFd,buffer,size);
        free(buffer);
        

    }

    close(infoFileFd);
    close(dataFileFd);
    closedir(dp);

    return 0;
}