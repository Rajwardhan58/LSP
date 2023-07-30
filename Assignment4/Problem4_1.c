//write a program which is used to demonsration concept of I/O redirection

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
    int a=atoi(argv[1]);
    int b = atoi(argv[2]);

    int ans=a+b;

    printf("Addition is : %d",ans);
    return 0;
}