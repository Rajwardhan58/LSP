//write a program which writes structure in file.Structure should contains information of student.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#pragma pack(1)

struct Student
{
    char Sname[20];
    int RollNo;
    int Age;
    float Marks;
};

int main(int argc,char *argv[])
{
    struct Student sobj;
    char Fname[20];
    int fd=0;

    if(argc!=2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    sobj.RollNo=11;
    sobj.Marks=89.99f;
    sobj.Age=25;
    strcpy(sobj.Sname,"Ram");

    fd=open(argv[1],O_RDONLY);
    if(fd==0)
    {
        printf("file is already exist\n");
        close(fd);
        return -1;
    }

    write(fd,&sobj,sizeof(sobj));
    read(fd,&sobj,sizeof(sobj));

    printf("Roll number : %d : \n",sobj.RollNo);
    printf("name : %s : \n",sobj.Sname);
    printf("Age : %d : \n",sobj.Age );
    printf("Marks : %f : \n",sobj.Marks);
    close(fd);
    return 0;
}