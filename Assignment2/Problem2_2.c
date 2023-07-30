//Write a program which accept file name from user and write string in that file.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#define BLOCKSIZE 1024
int main(int argc,char *argv[])
{
	int fd=0;
	int Ret= 0 ;
	char buffer[]="Marvellous";
	if(argc!=2)
	{
		printf("Usage : Name_Of_Executable_File Name_Of_File\n");
		return -1;
	}
	
	fd = open(argv[1],O_RDWR);
	if(fd==-1)
	{
		return 1;
	}
 
	write(fd,buffer,strlen(buffer));
	
	close(fd);
	return 0;
}
