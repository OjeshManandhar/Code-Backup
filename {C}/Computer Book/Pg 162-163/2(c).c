#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=1,x=0,s=0;
    while (i<=99)
    {
        printf("%d ",i);
        x++;
        s+=i;
        i+=2;
    }
    printf("\n\nSum of the series is %d and average is %.2f.\n",s,s/(x*1.0));
    return 0;
}
