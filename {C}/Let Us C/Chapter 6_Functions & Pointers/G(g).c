#include <stdio.h>
#include <stdlib.h>

int sum(int,int);
int main()
{
    int i=1,n=0,s;
    s=sum(i,n);
    printf("The sum of natural numbers up to 25 is: %d.\n",s);
    return 0;
}

int sum(int i,int n)
{
    if (i<=25)
        n=sum(i+1,n+i);
    else
        return n;
    return n;
}
