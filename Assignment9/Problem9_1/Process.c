#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
    DIR *dp=NULL;
    struct dirent *entry=NULL;
    struct stat sobj;
    int fd=0;
    char name[30]={'\n'};
    char FileName[30]={'\n'};


    dp=opendir("/home/rajwardhan58/Desktop");
    if(dp==NULL)
    {
        return -1;
    }
    fd=open("/home/rajwardhan58/Desktop/Demo.txt", O_RDWR | O_APPEND| O_CREAT,0777);
    if(fd<0)
    {
        printf("cant open file\n");
        return -1;
    }
    while((entry=readdir(dp))!=NULL)
    {
        sprintf(name,"%s/%s","/home/rajwardhan58/Desktop",entry->d_name);
        printf("%s\n",entry->d_name);
        stat(name,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            strcpy(FileName,entry->d_name);
            write(fd,FileName,strlen(FileName));
            write(fd,"\n",1);
        }
    }
    return 0;
}