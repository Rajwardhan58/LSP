//write a program which accept directory name from user and write information of all regular file in text file and read the contents of that file

#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
#pragma pack(1)
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
    DIR *dp;
    struct dirent *entry;
    char buffer[1024]   = {'\0'};
    int fd=0,readCount  = 0;
    char buf[20]        = {'\0'};

    if(argc!=3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    dp=opendir(argv[1]);
    fd=open(argv[2],O_RDWR);

    if(dp==NULL || fd<0)
    {
        printf("%d",fd);
        printf("Cant open the file\n");
        return -1;
    }

    while((entry=readdir(dp))!=NULL)
    {
        sprintf(buf,"%s/%s",argv[1],entry->d_name);
        struct stat sobj;
        struct FileInfo fobj;

            stat(buf,&sobj);

        if (S_ISREG(sobj.st_mode)) 
        {
            
            

            //fobj.mode="Regular File";
            strcpy(fobj.name,entry->d_name);
            strcpy(fobj.mode,"Regular File");
            fobj.inode=sobj.st_ino;
            fobj.linkNum=sobj.st_nlink;
            fobj.devId=sobj.st_dev;
            fobj.size=sobj.st_size;
            int no=write(fd,&fobj,sizeof(fobj));

             //printf("%s\n",entry->d_name);
             //printf("%d\n",no);
            
         } 
         else
         {
            continue;
         }
        
    }
    int bytesRead;
    struct FileInfo tobj;
    fd = open(argv[2], O_RDONLY);
    if (fd == -1) 
    {
        perror("Error opening file");
        return 1;
    }
    while((bytesRead=read(fd,&tobj,sizeof(tobj)))>0)
    {
        printf("File Name   :   %s\n",tobj.name);
        printf("File Type   :   %s\n",tobj.mode);
        printf("Inode Number:   %d\n",tobj.inode);
        printf("Link Count  :   %d\n",tobj.linkNum);
        printf("Device Id   :   %d\n",tobj.devId);
        printf("File Size   :   %d\n",tobj.size);
        printf("----------------------------------\n");

    }
    //printf("%d\n",bytesRead);
    close(fd);
    closedir(dp);
    return 0;
}