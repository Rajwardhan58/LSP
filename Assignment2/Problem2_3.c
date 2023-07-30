//write a program which accept directory name from user and print all file names from that directory

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc,char* argv[])
{
	DIR *dp = NULL;
	
	struct dirent *entry =NULL;
	
	if(argc!=2)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	dp = opendir(argv[1]);
	
	if(dp==NULL)
	{
		printf("UNable to open directory\n");
		return -1;
	}
	
	printf("File Names : \n");
	while((entry =readdir(dp))!=NULL)
	{
		printf("%s  \n",entry->d_name);
	}
	
	closedir(dp);
	return 0;
}
