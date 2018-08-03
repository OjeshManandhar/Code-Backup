#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    printf("Enter 2 numbers(a and b): ");
    scanf("%d%d",&a,&b);
    if (b%a==0)
        printf("\n%d(b) is divisible by %d(a).\n",b,a);
    else
        printf("\n%d(b) is not divisible by %d(a).\n",b,a);
    return 0;
}
