#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n;
    float x,l;
    printf("Enter the number of numbers among which you want to pick the largest: ");
    scanf("%d",&n);
    printf("\n");
    printf("Enter the number no.1: ");
    scanf("%f",&x);
    l=x;
    for (i=2;i<=n;i++)
    {
        printf("Enter the number no.%d: ",i);
        scanf("%f",&x);
        if (x>l)
            l=x;
    }
    printf("\nThe largest number is: %.2f.\n",l);
    return 0;
}
