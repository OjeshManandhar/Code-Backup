#include <stdio.h>
#include <stdlib.h>
#include "interest.h"

int main()
{
    float p,t,r,i,a;
    printf("Enter PRINCIPAL: ");
    scanf("%f",&p);
    printf("Enter TIME: ");
    scanf("%f",&t);
    printf("Enter RATE: ");
    scanf("%f",&r);
    SI(p,t,r,i);
    printf("\nThe INTEREST is: Rs.%.2f.\n",i);
    AM(i,p,a);
    printf("\nThe AMMOUNT is: Rs.%.2f.\n",a);
    return 0;
}
