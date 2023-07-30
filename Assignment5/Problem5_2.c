#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#pragma pack(1)

struct Student
{
    int Rollno;
    char Sname[20];
    float Marks;
    int Age;
};

int main(int argc , char *argv[])
{
    struct Student sobj;
    char Fname[20];
    int fd=0;
    if(argc!=2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    fd=open(argv[1],O_RDONLY);
    if(fd<0)
    {
        return -1;
    }
    read(fd,&sobj,sizeof(sobj));

    printf("Roll number : %d : \n",sobj.Rollno);
    printf("name : %s : \n",sobj.Sname);
    printf("Age : %d : \n",sobj.Age );
    printf("Marks : %f : \n",sobj.Marks);
    

    

    return 0;
}