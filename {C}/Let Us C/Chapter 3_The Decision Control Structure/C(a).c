#include <stdio.h>
#include <stdlib.h>

int main()
{
    float sp,cp,p,l;
    printf("Enter Cost Price:");
    scanf("%f",&cp);
    printf("Enter Selling Price:");
    scanf("%f",&sp);
    if (sp>cp)
    {
        printf("\nSeller has made Profit.\n");
        printf("Profit amount: %.2f",sp-cp);
    }
    else if (cp>sp)
    {
        printf("\nSeller has incurred loss.\n");
        printf("Loss amount: %.2f",cp-sp);
    }
    return 0;
}
