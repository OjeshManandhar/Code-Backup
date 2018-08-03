#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,s=0;
    for (i=1;i<=500;i++)
        if (i%5==0)
            s+=i;
    printf("The sum of numbers between 1 and 500 which are divisible by 5 is %d.\n",s);
    return 0;
}
