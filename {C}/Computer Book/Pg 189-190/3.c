#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,x;
    float *n;
    const float pi=3.141592653589793;
    printf("Enter the number of circles of which you want to calculate are and circumference: ");
    scanf("%d",&x);
    n=(float *)malloc(x);
    printf("\n");
    for (i=0;i<x;i++)
    {
        printf("Enter the radius of circle no.%d: ",i+1);
        scanf("%f",&n[i]);
    }
    printf("\nThe area and circumference are:\n");
    for (i=0;i<x;i++)
        printf("Area is %.2f and circumference is %.2f, of circle no.%d.\n",pi*n[i]*n[i],2*pi*n[i],i+1);
    return 0;
}
