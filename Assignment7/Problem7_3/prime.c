#include "prime.h"

bool Prime(int no)
{
    int i=2;
    if(no==1)
    {
        return true;
    }   

    while(i<=(no/2))
    {
        if(no%i==0)
        {
            break;
        }
        i++;
    }

    if(i==(no/2)+1)
    {
        return true;
    }
    else
    {
        return false;
    }

}