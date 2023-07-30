//write a program which accept directory name from user and combine all contents of file from that directory into one file named as AllCombine


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#define BUFFER_SIZE

int main(int argc,char *argv[])
{
    DIR *dp;
    struct dirent *entry;
    struct stat sobj;
    int fd,fileFd=0;
    char buffer[BUFFER_SIZE]={'\0'};
    char buf[20];
    if(argc!=2)
    {
        printf("Insufficient count\n");
        return -1;
    }

    dp=opendir(argv[1]);
    fd=open("AllCombine.txt",O_RDWR | O_APPEND | O_CREAT);

    if(dp==NULL || fd<0)
    {
        printf("Cant open the file\n");
        return -1;
    }

    while((entry=readdir(dp))!=NULL)
    {
        sprintf(buf,"%s/%s",argv[1],entry->d_name);

        stat(buf,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            fileFd=open(buf,O_RDONLY);
            if(fileFd<0)
            {
                printf("Cant open the file\n");
                return -1;
            }
            write(fd,"\n//start\n",9);
            while((read(fileFd,buffer,sizeof(buffer)))!=0)
            {
               // sprintf()
                write(fd,buffer,sizeof(buffer));
                memset(buffer,0,sizeof(buffer));
            }
            write(fd,"\n//end\n",7);
            close(fileFd);
        }
    }

    close(fd);
    closedir(dp);
    return 0;
}