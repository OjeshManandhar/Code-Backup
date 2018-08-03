#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n[25],i,min;
    for (i=0;i<25;i++)
    {
        printf("Enter the %d number: ",i+1);
        scanf("%d",&n[i]);
    }
    int *p=n;
    min=*p;
    for (i=1;i<25;i++)
        if (*(p+i)<min)
            min=*(p+i);
    printf("\nThe smallest number is: %d.\n",min);
    return 0;
}
