//write a program which creates two processes and that two process communicate with each other by using concept of shared memory
//first process used to create shared memory 

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/shm.h>

int main()
{   
    int shmid=0;
    int shmsize=50;
    int key = 1234;
    char *ptr = NULL;

    shmid=shmget(key,shmsize,IPC_CREAT | 0666);

    printf("Shared memory allocated succesfully\n");

    ptr = shmat(shmid,NULL,0);

    if(ptr!=NULL)
    {
        printf("shared memory atached successfully...\n");
    }
    *ptr='H';
    ptr++;
    *ptr='e';
    ptr++;*ptr='l';
    ptr++;*ptr='l';
    ptr++;*ptr='o';
    ptr++;
    *ptr='\0';
    return 0;
}