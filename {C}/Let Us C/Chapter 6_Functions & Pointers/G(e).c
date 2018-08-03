#include <stdio.h>
#include <stdlib.h>

void series(int,int,int);
int main()
{
    int i=1,a=1,b=1;
    series(i,a,b);
    return 0;
}

void series(int i,int a,int b)
{
    int c=a+b;
    if (i<=25)
    {
        printf("%d ",a);
        a=b;
        b=c;
        i++;
        series(i,a,b);
    }
    else
        exit (1);
}
