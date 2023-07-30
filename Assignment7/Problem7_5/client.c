#include<stdio.h>
#include "FileInfo.h"

int main(int argc,char *argv[])
{
    if(argc!=2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }
    FileInfo(argv[1]);
    return 0;
}