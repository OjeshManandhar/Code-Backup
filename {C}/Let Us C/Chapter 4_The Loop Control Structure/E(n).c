#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    float p=100000;
    for (i=10;i>=1;i--)
    {
        printf("Population at the end of year %d is: %.3f.\n",i,p);
        p-=p*10/100;
    }
    return 0;
}
