//client for shared memory
//second process used to use the shared memory 


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/shm.h>
int main()
{
    int shmid=0;
    int shmsize=50;
    int key = 1234;
    char *ptr=NULL;

    shmid=shmget(key,shmsize,0666);

    printf("Shared memory allocated succesfully..\n");

    ptr=shmat(shmid,NULL,0);

    if(ptr!=NULL)
    {
        printf("shared memory atached successfully...\n");
    }

    printf("Data\n");

    while(*ptr!='\0')
    {
        printf("%c",*ptr);
        ptr++;
    }
    shmdt(ptr);
    return 0;

}