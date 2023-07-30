//Write a program which accept file name and number of bytes from  user  and  read that number of bytes from file
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	int fd=0,numBytes=0,insertSize=1024;
	int readCount=0;
	numBytes=atoi(argv[2]);
	char *buffer;
	if(argc!=3)
	{
		printf("Usage : Name_Of_Executable_File Name_Of_File Number_Of_Bytes\n");
		return -1;
	}
	
	fd=open(argv[1],O_RDONLY);
	buffer=(char *)malloc(numBytes*sizeof(char));
	if(fd<0)
	{
		printf("Can't open file\n");
		return -1;
	}
	memset(buffer,0,sizeof(buffer));
	
	readCount=read(fd,buffer,numBytes);
	printf("%d\n",readCount);
	close(fd);

	
	return 0;
}
