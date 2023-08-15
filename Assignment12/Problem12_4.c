//write a program which map any file in memory and read the data from that mapped file.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/shm.h>
#include<sys/mman.h>
int main()
{
    char *ptr=NULL;
    struct stat eobj;
    int fileSize=0;

    int fd=open("gold.txt",O_RDONLY);
    if(fd<0)
    {
        printf("Unable to open file\n");
        return -1;
    }

    if(fstat(fd,&eobj)==0)
    {
        fileSize=(int)eobj.st_size;
    }
    printf("size of file is %d\n",fileSize);
    ptr=mmap(NULL,fileSize,PROT_READ,MAP_SHARED,fd,0);
    printf("File contents : \n%s\n",ptr);

    close(fd);


    return 0;
}