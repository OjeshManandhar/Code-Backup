#include <stdio.h>
#include <stdlib.h>

int main()
{
    float sp,cp,pro;
    printf("Total Selling price of 15 items: ");
    scanf("%f",&sp);
    printf("Total Profit earned: ");
    scanf("%f",&pro);
    cp=(sp-pro)/15;
    printf("\nCost price of 1 item is: %.2f.\n",cp);
    return 0;
}
