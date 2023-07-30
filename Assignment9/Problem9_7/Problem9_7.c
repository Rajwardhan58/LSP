#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>
#include<string.h>
extern char **environ;

int main()
{
   char **env = environ;
    char* pwd = NULL;
    char *usr=NULL;
   printf("Environment of running process is : \n");

   while(*env!=NULL)
   {
    if (strncmp(*env, "PWD=", 4) == 0) 
    {
        pwd = *env + 4; 
    }
    if (strncmp(*env, "LOGNAME=", 8) == 0) 
    {
        usr = *env + 8;     
    }
    env++;
   }

   if(pwd!=NULL && usr!=NULL)
   {
    printf("Current working directory: %s\n", pwd);
    printf("Log in user name: %s\n", usr);

   }
    return 0;
}