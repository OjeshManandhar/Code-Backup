#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,i=1,o=0,r;
    printf("Enter an integer: ");
    scanf("%d",&a);
    while (a>0)
    {
        r=a%8;
        o+=r*i;
        a/=8;
        i*=10;
    }
    printf("\nThe OCTAL equivalent is: %d.\n",o);
    return 0;
}
