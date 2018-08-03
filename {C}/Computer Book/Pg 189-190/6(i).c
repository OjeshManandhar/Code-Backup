#include <stdio.h>
#include <stdlib.h>

#include <swap.h>

int main()
{
    float n[10];
    int i,j;
    printf("Enter 10 elements of the numeric array.\n");
    for (i=0;i<10;i++)
    {
        printf("Enter element no.%d: ",i+1);
        scanf("%f",&n[i]);
    }
    printf("\nThe entered numbers are in following order: \n");
    for (i=0;i<10;i++)
        printf("%.1f ",n[i]);
    for (i=0;i<10;i++)
        for (j=i+1;j<10;j++)
            if(n[i]>n[j])
                swapi(&n[i],&n[j]);
    printf("\nSorting the numbers in ascending order,\nThe new order of numbers is:\n");
    for (i=0;i<10;i++)
        printf("%.1f ",n[i]);
    return 0;
}
