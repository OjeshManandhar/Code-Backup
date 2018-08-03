#include <stdio.h>
#include <stdlib.h>

void shift (int *);
int main()
{
    int mat[4][5],i,j;
    printf("Create a 4X5 matrix.\n");
    for (i=0;i<4;i++)
        for(j=0;j<5;j++)
        {
            printf("Enter the [%d][%d] element: ",i+1,j+1);
            scanf("%d",&mat[i][j]);
        }
    printf("\nThe matrix you have created is:\n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<5;j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }
    int (*p)[5];
    for (i=0;i<5;i++)
    {
        p=&mat[i];
        shift (p);
    }
    printf("\nShifting the row to left.\n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<5;j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }
    return 0;
}

void shift (int *a)
{
    int i,n[5];
    for (i=0;i<5;i++)
        n[i]=a[i];
    for (i=0;i<5;i++)
        if (i<=2)
            a[i]=n[i+2];
        else
            a[i]=n[i-3];
}
