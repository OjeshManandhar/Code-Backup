#include <stdio.h>
#include <stdlib.h>

int main()
{
    int no;
    printf("Enter the number of elements of your array:  ");
    scanf("%d",&no);
    int n[no],i,temp,x;
    for (i=0;i<no;i++)
    {
        printf("Enter element no. %d:  ",i+1);
        scanf("%d",&n[i]);
    }
    printf("\nThe number you have entered is in this order: \n\t");
    for (i=0;i<no;i++)
        printf("%d ",n[i]);
    if (no%2==0)
        x=no;
    else
        x=no-1;
    for (i=0;i<x;i=i+2)
    {
        temp=n[i];
        n[i]=n[i+1];
        n[i+1]=temp;
    }
    printf("\nExchanging the odd and even elements.\nThe new order is:\n\t");
    for (i=0;i<no;i++)
        printf("%d ",n[i]);
    return 0;
}
