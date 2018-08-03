#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check(float,float);

int main()
{
    float cp,sp;
    printf("Enter the selling price: Rs.");
    scanf("%f",&sp);
    printf("Enter the cost price: Rs.");
    scanf("%f",&cp);
    check(sp,cp);
    return 0;
}

void check(float sp,float cp)
{
    if (sp>cp)
        printf("\nProfit.\n");
    else if (cp>sp)
        printf("\nLoss.\n");
    else
        printf("\nNeither profit nor loss.\n");
}
