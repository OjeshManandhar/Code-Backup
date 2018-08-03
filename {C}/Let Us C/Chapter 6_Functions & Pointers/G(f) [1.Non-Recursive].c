#include <stdio.h>
#include <stdlib.h>

int binary(int);
int main()
{
    int a,ans;
    printf("Enter an integer: ");
    scanf("%d",&a);
    ans=binary(a);
    printf("\nThe BINARY equivalent is: %d.\n",ans);
    return 0;
}

int binary(int a)
{
    int i=1,r,b=0;
    while (a>0)
    {
        r=a%2;
        b+=r*i;
        a/=2;
        i*=10;
    }
    return b;
}
