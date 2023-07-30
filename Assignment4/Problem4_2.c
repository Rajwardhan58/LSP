//write a program which accept directory name from user and create new directory of that name.

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        return -1;
    }
    int ret=mkdir(argv[1],0777);
    if(ret<0)
    {
        return -1;
    }
    printf("directory created successfully\n");
    return 0;
}