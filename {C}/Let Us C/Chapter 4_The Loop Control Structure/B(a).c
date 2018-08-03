#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=1,t;
    while (i<=10)
    {
        printf("Enter the number of hours of the Overtime of the employee: ");
        scanf("%d",&t);
        if (t>40)
            printf("Amount of overtime paid is: Rs.%.2f.\n\n",(t-40)*12.0);
        else
            printf("Overtime is NOT MORE than 40 hours.\n\n");
        i++;
    }
    return 0;
}
