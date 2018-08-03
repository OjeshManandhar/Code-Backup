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
    int b,r;
    if (a==0)
        return 0;
    else
    {
        r=a%2;
        b=10*binary(a/2)+r;
    }
    return b;
}
