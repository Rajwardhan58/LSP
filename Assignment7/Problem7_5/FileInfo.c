#include "FileInfo.h"

void FileInfo(char *name)
{
    int fd=0;
    struct stat sobj;
    fd=open(name,O_RDONLY);
    if(fd<0)
    {
        printf("%d",fd);
        printf("Cant open the file\n");
        return;
    }
    int ret=stat(name,&sobj);
    if(ret==0)
    {
        printf("File Name   :   %s\n",name);
        if (S_ISREG(sobj.st_mode))
            printf("File Type   :   REGULAR\n");
        else
            printf("File Type   :   SPECIAL\n");
        printf("Inode Number:   %d\n",sobj.st_ino);
        printf("Link Count  :   %d\n",sobj.st_nlink);
        printf("Device Id   :   %d\n",sobj.st_dev);
        printf("File Size   :   %d\n",sobj.st_size);
        printf("----------------------------------\n");
    }
    else
    {
        printf("can't get info\n");
    }

    close(fd);
        

}