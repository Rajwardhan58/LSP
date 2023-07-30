//write a program which accept two directory names from user and move all files from source directory to destination directory

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>

int main(int argc,char *argv[])
{
     DIR *dp;
     struct dirent *entry;
     char Sname[20];
     char Dname[20];

    int res=0;
    if(argc!=3)
    {
        printf("Insufficient argument\n");
        return -1;
    }
    
     dp=opendir(argv[1]);

     if(dp==NULL)
     {
        printf("cant open directory\n");
        return -1;
     }
    
     while ((entry = readdir(dp)) != NULL) 
     {
         if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) 
         {
            continue; 
         }
        sprintf(Sname,"%s/%s",argv[1],entry->d_name);
        sprintf(Dname,"%s/%s",argv[2],entry->d_name);
        //printf("%s\n",Sname);
        //printf("%s\n",Dname);
        rename(Sname,Dname);
     }

    
    return 0;
}