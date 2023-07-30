//write a program which accept file name which contains data of all files.we have to print all file names whose size is greater than 10 bytes


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#define BUFFER_SIZE 1024

int main(int argc,char *argv[])
{
    DIR *dp;

    int fd=0,newFd=0;
    int fileNo=1;
    char fileName[20]={'\0'};
    int bytesRead=0;
    char line[BUFFER_SIZE]={'\n'};
    char buffer[BUFFER_SIZE]={'\n'};
    int lineLength=0;
    if(argc!=2)
    {
        printf("Insufficient count\n");
        return -1;
    }

    fd=open(argv[1],O_RDONLY);

    if(fd<0)
    {
        printf("cant open file\n");
        return -1;
    }
    while((bytesRead=read(fd,buffer,BUFFER_SIZE))!=0)
    {
         for (ssize_t i = 0; i < bytesRead; i++) 
         {
            if (buffer[i] == '\n') 
            {
                line[lineLength] = '\0';
                //printf("Line: %s\n", line);
                if(strcmp(line,"//start")==0)
                {
                    
                }     
                else if(strcmp(line,"//end")==0) 
                {
                    lineLength = 0;
                }          
                else 
                {
                    //printf("write in file\n");
                }
                // Reset the line buffer for the next line
                
            } 
            else 
            {
                line[lineLength] = buffer[i];
                lineLength++;
                if (lineLength == BUFFER_SIZE - 1) {

                    line[lineLength] = '\0';
                    //printf("Line: %s\n", line);

                    lineLength = 0;
                }
            }
         }   
    }
    close(fd);
    closedir(dp);
    return 0;
}