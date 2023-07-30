//write a program which accept directory name from user and print all file names and its types from that directory

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
	
	printf("File Names  \tFile type  \n");
	while((entry =readdir(dp))!=NULL)
	{
		printf("%10s : \t",entry->d_name);

		switch(entry->d_type)
		{
			 case DT_REG:
            printf("Regular File\n");
            break;
        case DT_DIR:
            printf("Directory\n");
            break;
        case DT_FIFO:
            printf("FIFO (Named Pipe)\n");
            break;
        case DT_BLK:
            printf("Block Device\n");
            break;
        case DT_CHR:
            printf("Character Device\n");
            break;
        case DT_LNK:
            printf("Symbolic Link\n");
            break;
        case DT_SOCK:
            printf("Socket\n");
            break;
        default:
            printf("Unknown\n");
         
		}
	}
	
	closedir(dp);
	return 0;
}
