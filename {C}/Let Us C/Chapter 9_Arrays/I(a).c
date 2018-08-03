#include <stdio.h>
#include <stdlib.h>

int main()
{
    int no;
    printf("Enter the number of elements of your array:  ");
    scanf("%d",&no);
    int n[no],rev[no],i,j;
    for (i=0;i<no;i++)
    {
        printf("Enter element no. %d: ",i+1);
        scanf("%d",&n[i]);
    }
    printf("\nThe array you have created is:\n\t");
    for (i=0,j=no-1;i<no;i++,j--)
    {
        printf("%d ",n[i]);
        rev[j]=n[i];
    }
    printf("\nReversing the array you have created:\n\t");
    for (i=0;i<no;i++)
        printf("%d ",rev[i]);
    return 0;
}
