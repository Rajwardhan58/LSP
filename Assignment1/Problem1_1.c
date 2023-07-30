//Write a program which accept file name from user and open that

#include<stdio.h>
#include<fcntl.h>


int main(int argc,char *argv[])
{

	int fd=0;
	if(argc!=2)
	{
		printf("Usage : Name_Of_Executable_File Name_Of_File \n");
		return -1;
	}
	
	fd=open(argv[1],O_RDONLY);
	
	if(fd<0)
	{
		printf("Can't open file\n");
		return -1;
	}
	
	printf("file opened successfully with fd : %d\n",fd);
	
	close(fd);
	
	return 0;
}
