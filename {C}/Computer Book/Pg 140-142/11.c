#include <stdio.h>
#include <stdlib.h>

int main()
{
    int e,c;
    printf("Enter the unit consumption of electricity: ");
    scanf("%d",&e);
    if (e<=20)
        c=80;
    else if (e>20 && e<=30)
        c=80+6*(e-20);
    else
        c=80+6*10+8*(e-30);
    printf("\nTotal amount: Rs.%d.\n",c);
    return 0;
}
