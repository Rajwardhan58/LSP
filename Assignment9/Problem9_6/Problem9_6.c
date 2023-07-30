#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>

extern char **environ;

int main()
{
   char **env = environ;

   printf("Environment of running process is : \n");

   while(*env!=NULL)
   {
    printf("%s : \n",*env);
    env++;
   }
    return 0;
}