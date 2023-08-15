//client

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
int main()
{
    int fd=0;
    char *path="/tmp/tempPipe";
    char Buffer[100]={'\n'};

    

    printf("client is running and reading data into named pipe....\n");

    fd= open(path,O_RDONLY);

    read(fd,Buffer,sizeof(Buffer));


    printf("Data from pipe : %s\n",Buffer);
    
    return 0;
}