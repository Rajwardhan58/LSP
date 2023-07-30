//Write program which accept directory name from user and delete all empty files from that directory

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
int main(int argc,char *argv[])
{
    DIR *dp=NULL;
    struct dirent *entry=NULL;
    struct stat sobj;
    char sourceDir[20]={'\n'};
    if(argc!=2)
    {
        printf("insufficient arguments\n");
        return -1;
    }

    dp=opendir(argv[1]);

    if(dp==NULL)
    {
        printf("cant open directory\n");
        return -1;
    }

    while((entry=readdir(dp))!=NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) 
        {
           continue; 
        }

        sprintf(sourceDir,"%s/%s",argv[1],entry->d_name);

        stat(sourceDir,&sobj);
        if(sobj.st_size==0)
        {
            if (remove(sourceDir) == 0) 
            {
                printf("File deleted successfully.\n");
            } 
            else 
            {
                perror("Error deleting file");
                return -1;
            }
        }
        
        
    }

    closedir(dp);
    return 0;
}