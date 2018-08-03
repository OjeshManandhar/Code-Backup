#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x[]={-6,-12,8,13,11,6,7,2,-6,-9,10,11,10,9,2},i,sum=0;
    float mean,sd=0;
    printf("The numbers of which we are calculating Standard Deviation are:\n");
    for (i=0;i<15;i++)
    {
        printf("%d ",x[i]);
        sum+=x[i];
    }
    printf("\n");
    mean=sum/15.0;
    for (i=0,sum=0;i<15;i++)
        sd+=pow(x[i]-mean,2);
    sd=pow(sd/15.0,0.5);
    printf("\nThe Standard Deviation of the numbers is: %.3f.\n",sd);
    return 0;
}
