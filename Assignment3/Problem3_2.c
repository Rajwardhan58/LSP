//write a program which accept directory name and file name from user and and check whether that file is present in that directory or not

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<stdbool.h>
#include<dirent.h>

int main(int argc,char *argv[])
{
    DIR *dp;
    struct dirent *entry;
    bool flag=false;
    if(argc!=3)
    {
        printf("Insufficient parameter\n");
        return -1;
    }

    dp=opendir(argv[1]);
    if (dp == NULL) 
    {
        printf("Unable to open the directory.\n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL) 
    {
        printf("%s\n",entry->d_name);
        if((strcmp(argv[2],entry->d_name))==0)
        {
            flag=true;
            break;
        }
    }

    if(flag)
    {
        printf("file is present in that directory\n");
    }
    else
    {
        printf("file is not present in that directory\n");
    }

    closedir(dp);
   return 0;
}