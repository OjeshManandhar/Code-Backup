#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,f,x;
    float a[10],n;
    printf("Enter the 10 elements of the numeric array:\n");
    for (i=0;i<10;i++)
    {
        printf("Enter element no.%d: ",i+1);
        scanf("%f",&a[i]);
    }
    printf("\nEnter the element you want to search: ");
    scanf("%f",&n);
    for (i=0;i<10;i++)
        if (a[i]==n)
        {
            f=1;
            x=i+1;
            break;
        }
        if (f==1)
            printf("\nThe element you were searching is the %d element.\n",x);
        else
            printf("\nThe element you were searching is not found.\n");
    return 0;
}
