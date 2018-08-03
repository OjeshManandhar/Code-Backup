#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i=1,f=1;
    printf("Enter any number: ");
    scanf("%d",&n);
    while (i<=n)
    {
        f*=i;
        i++;
    }
    printf("\nFactorial Value: %d.\n",f);
    return 0;
}
