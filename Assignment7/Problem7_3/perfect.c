#include "perfect.h"

bool Perfect(int no)
{
    int i=1;
    int result=0;
    while(i<=(no/2))
    {
        if(no%i==0)
        {
            result=result+i;
        }
        i++;
    }

    if(result == no)
    {
        return true;
    }
    else
    {
        return false;
    }
}

