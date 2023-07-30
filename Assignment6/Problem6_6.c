//write a program which accept directory name from user and create a hole in file if size is less than 1kb and if it is greater than 1kb then truncate the remaining data.


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#define SIZE 1024
int main(int argc,char *argv[])
{
    DIR *dp;
    struct dirent *entry;
    struct stat sobj;
    int fd=0,readCount=0;
    char fileName[20]={'\n'};
    if(argc!=2)
    {
        printf("Insufficient count\n");
        return -1;

    }
    dp=opendir(argv[1]);

    while((entry = readdir(dp))!=NULL)
    {
            sprintf(fileName,"%s/%s",argv[1],entry->d_name);
            stat(fileName,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            fd=open(fileName,O_RDWR);
            if(sobj.st_size<=SIZE)
            {
                if (lseek(fd, 0, SEEK_END) == -1) {
                perror("Error seeking to create hole");
                close(fd);
                return -1;
                }
                char hole_data[SIZE] = {'\n'};
                memset(hole_data,32,SIZE);
                if (write(fd, hole_data, SIZE) == -1) {
                    perror("Error writing hole to file");
                    close(fd);
                    return -1;
                }
            }
            else
            {
                if (truncate(fileName ,SIZE) == -1) 
                {
                perror("truncate");
                close(fd);
                return 1;
                }
            }
        }


    }

    

    close(fd);
    closedir(dp);
    return 0;

}