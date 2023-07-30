//write a program which create hole of size 1kb at the end of file

#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#define KBHOLE 1024

int main(int argc,char *argv[])
{
    int fd=0;
    if(argc!=2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    fd=open(argv[1],O_RDWR);
    if(fd<0)
    {
        printf("cant open file\n");
        return -1;
    }

    if (lseek(fd, 0, SEEK_END) == -1) {
        perror("Error seeking to create hole");
        close(fd);
        return -1;
    }
    char hole_data[KBHOLE] = {'\n'};
    memset(hole_data,32,KBHOLE);
    if (write(fd, hole_data, KBHOLE) == -1) {
        perror("Error writing hole to file");
        close(fd);
        return -1;
    }

    write(fd,"hii",3);

    printf("1 kb of hole created successfully\n");
    close(fd);
    return 0;
}