#include "in.h"

long int Factorial(int no)
{
    if(no<=0)
    {
        return -1;
    }
    if(no==1)
        return 1;
    
    long int res=Factorial(no-1);
    return no*res;
}