#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    printf("Inside Child Process pid : %d\n",getpid());
    return 0;
}