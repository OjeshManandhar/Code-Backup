#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d;
    printf("Enter the number of day(s): ");
    scanf("%d",&d);
    if (d<30)
        printf("\n%d day(s).\n",d);
    else if (d<365)
        printf("\n%d month(s): %d day(s).\n",d/30,d%30);
    else
        printf("\n%d year(s): %d month(s): %d day(s).\n",d/365,(d%365)/30,(d%365)%30);
    return 0;
}
