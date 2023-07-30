//Write a program which accept file name from user  and print all information about that file
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>


int main(int argc,char *argv[])
{

	struct stat fileStat;
	
	if(argc!=2)
	{
		printf("Usage : Name_Of_Executable_File Name_Of_File  \n");
		
		return -1;
	}
	
	int iRet=stat(argv[1],&fileStat);
	
	if(iRet==0)
	{
		printf("file name : %s\n",argv[1]);
		printf("File system number : %ld\n",fileStat.st_dev);
		printf("Inode number : %ld\n",fileStat.st_ino);
		printf("FIle mode %o\n",fileStat.st_mode);
		printf("Number of hardlinks : %lu\n",fileStat.st_nlink);
		printf("file size is : %ld\n",fileStat.st_size);
		printf("UID: %d\n", fileStat.st_uid);
		printf("Number of blocks :%ld\n",fileStat.st_blocks);		
	}
	else
	{
		printf("can't get file information");
	}
	
	
	
	return 0;
}
