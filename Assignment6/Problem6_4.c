//write a program which accept directory name from user and delete all such files whose size is greater than 100 bytes

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
    struct dirent *entry;
    struct stat sobj;
    int fd=0;
    char fileName[20]={'\0'};
    
    if(argc!=2)
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

    while((entry=readdir(dp))!=NULL)
    {
        sprintf(fileName,"%s/%s",argv[1],entry->d_name);
        stat(fileName,&sobj);
        if(sobj.st_size>=100 && S_ISREG(sobj.st_mode))
        {
            if (unlink(fileName) == -1) 
            {
                perror("Error deleting file");
                return -1;
            }
        }
    }

    close(fd);
    closedir(dp);
    return 0;
}
