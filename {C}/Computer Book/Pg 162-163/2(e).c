#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=1,n,x=0,s=0;
    n=i*i;
    while (n<=100)
    {
        printf("%d ",n);
        x++;
        i++;
        s+=n;
        n=i*i;
    }
    printf("\n\nSum of the series is %d and average is %.2f.\n",s,s/(x*1.0));
    return 0;
}
