#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **mat,**tra,m,n,i,j;
    printf("If m x n be the size of the matrix then,\n");
    printf("Enter the values of m: ");
    scanf("%d",&m);
    printf("Enter the values of n: ");
    scanf("%d",&n);
    printf("\n");
    mat=(int **)malloc(m*sizeof(int *));
    for (i=0;i<m;i++)
        mat[i]=(int *)malloc(n);
    tra=(int **)malloc(n*sizeof(int *));
    for (i=0;i<n;i++)
        tra[i]=(int *)malloc(m);
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("Enter the value of element %d x %d: ",i+1,j+1);
            scanf("%d",&mat[i][j]);
        }
        printf("\n");
    }
    printf("\nThe matrix you have just created is:\n");
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
            printf("%d\t",mat[i][j]);
        printf("\n");
    }
    for (i=0;i<m;i++)
        for (j=0;j<n;j++)
            tra[j][i]=mat[i][j];
    printf("\nThe transpose of the matrix you have just created is:\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
            printf("%d\t",tra[i][j]);
        printf("\n");
    }
    return 0;
}
