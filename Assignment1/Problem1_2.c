//Write a program which accept file name and mode from user  and open that file in specified mode

#include<stdio.h>
#include<fcntl.h>
#include<string.h>


int main(int argc,char *argv[])
{

	int fd=0;
	int mode=0;
	if(argc!=3)
	{
		printf("Usage : Name_Of_Executable_File Name_Of_File  Mode_Of_File \n");
		printf("modes\t: read,write,read_write\n");
		return -1;
	}
	
	if(strcmp(argv[2],"read")==0)
	{
		mode=O_RDONLY;
	}
	else if(strcmp(argv[2],"write"))
	{
		mode=O_WRONLY;
	}
	else if(strcmp(argv[2],"read_write"))
	{
		mode=O_RDWR;
	}
	else
	{
		mode=O_RDONLY;	
	}
	fd=open(argv[1],mode);
	
	if(fd<0)
	{
		printf("Can't open file\n");
		return -1;
	}
	
	printf("file opened successfully with fd : %d\n",fd);
	
	close(fd);
	
	return 0;
}
