#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n[5][5],i,j;
    printf("Create a 5X5 matrix.\n");
    for (i=0;i<5;i++)
        for (j=0;j<5;j++)
        {
            printf("Enter the element [%d][%d]: ",i+1,j+1);
            scanf("%d",&n[i][j]);
        }
    printf("\nThe matrix you have created is: \n");
    for (i=0;i<5;i++)
    {
        for (j=0;j<5;j++)
            printf("%d\t",n[i][j]);
        printf("\n");
    }
    int max=n[0][0];
    for (i=0;i<5;i++)
        for (j=0;j<5;j++)
            if (n[i][j]>max)
                max=n[i][j];
    printf("\nThe greatest number among the elements of the matrix is: %d.\n",max);
    return 0;
}
