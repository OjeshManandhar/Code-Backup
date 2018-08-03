#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s,o;
    float r,c;
    printf("Enter the STOCK quantity of the product: ");
    scanf("%d",&s);
    printf("Enter the RATE of the product: ");
    scanf("%f",&r);
    printf("Enter the ORDERED quantity of the product: ");
    scanf("%d",&o);
    printf("Enter the CREDIT of the buyer: ");
    scanf("%f",&c);
    if (c<r*o)
        printf("\nDON'T supply the requirement.\n");
    else
    {
        if (o<=s)
            printf("\nSupply the requirement.\n");
        else
            printf("\nThe balance will be shipped LATER.\n");
    }
    return 0;
}
