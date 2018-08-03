#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **mat,m,n,i,j;
    printf("If m x n be the size of a integer matrix,\n");
    printf("Enter the values of m and n [SEPERATED BY A TAB]: ");
    scanf("%d%d",&m,&n);
    printf("\n");
    mat=(int **)malloc(m*sizeof(int *));
    for (i=0;i<m;i++)
        mat[i]=(int *)malloc(n*sizeof(int));
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("Enter the value of element %d x %d: ",i+1,j+1);
            scanf("%d",&mat[i][j]);
        }
        printf("\n");
    }
    printf("The matrix you have just created is:\n");
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
            printf("%d\t",mat[i][j]);
        printf("\n");
    }
    for (i=0;i<m;i++)
        free(mat[i]);
    free(mat);
    return 0;
}
