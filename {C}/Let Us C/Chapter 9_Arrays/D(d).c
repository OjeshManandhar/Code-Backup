#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num[25],i,p=0,n=0,o=0,e=0;
    for (i=0;i<25;i++)
    {
        printf("Enter element no. %d:  ",i+1);
        scanf("%d",&num[i]);
        if(num[i]>0)
            p++;
        if(num[i]<0)
            n++;
        if(num[i]%2==0)
            e++;
        else
            o++;
    }
    printf("\nNumber of POSITIVE numbers: %d\n",p);
    printf("Number of NEGATIVE numbers: %d\n",n);
    printf("Number of EVEN numbers: %d\n",e);
    printf("Number of ODD numbers: %d\n",o);
    return 0;
}
