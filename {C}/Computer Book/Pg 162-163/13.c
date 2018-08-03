#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s,i,n=0;
    float t;
    for (i=1;i<=10;i++)
    {
        printf("Enter the basic salary of person no.%d: ",i);
        scanf("%d",&s);
        t=(15.0/100.0)*s+(10/100.0)*s+(5/100.0)*s+s;
        if(t>4000)
            n++;
    }
    printf("\nThe number of person getting total salary more than 4000 is %d.\n",n);
    return 0;
}
