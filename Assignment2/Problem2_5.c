//write a program which accept directory name from user and print name of such a file having largest size

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>

int main(int argc,char* argv[])
{
	DIR *dp = NULL;
	struct stat fileStat;
	struct dirent *entry =NULL;
	int size=0;
	char *name=NULL;
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
	
	//printf("File Names  \tFile type  \n");
	while((entry =readdir(dp))!=NULL)
	{
		stat(entry->d_name,&fileStat);
		if(strcmp(entry->d_name,".")==0 || strcmp(entry->d_name,"..")==0)
		{continue;}
			
		printf("size : %d\n",fileStat.st_size);
		if(size<fileStat.st_size)
		{
			//printf("size : %d\n",size);
			size=fileStat.st_size;
			name=entry->d_name;
		}
		 
		
	}
	printf("File having largest size is : %s \n",name);
	closedir(dp);
	return 0;
}
