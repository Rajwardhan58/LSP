//write a program which creates two process as reader and writer and that process should communicate with each other using FIFO

//server

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
    char *Buffer="msg send successfully";
    fd = mkfifo(path,0666);

    if(fd == -1)
    {
        printf("UNable to create named pipe\n");
        return -1;
    }

    printf("server is running and writing data into named pipe....\n");

    fd= open(path,O_WRONLY);

    write(fd,Buffer,strlen(Buffer));

    close(fd);

    printf("Data successfully written in the pipe\n");
    
    return 0;
}