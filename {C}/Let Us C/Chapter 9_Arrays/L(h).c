#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s,i,j,k,br;
    printf("Enter the size of the square matrix you want to create: ");
    scanf("%d",&s);
    int mat[s][s],tra[s][s];
    for (i=0;i<s;i++)
        for (j=0;j<s;j++)
        {
            printf("Enter the element [%d][%d]: ",i+1,j+1);
            scanf("%d",&mat[i][j]);
        }
    printf("\nThe matrix you have created is:\n");
    for (i=0;i<s;i++)
    {
        for (j=0;j<s;j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }
    for (i=0;i<s;i++)
        for (j=0;j<s;j++)
            tra[i][j]=mat[j][i];
    printf("Transpose of the matrix is:\n");
    for (i=0;i<s;i++)
    {
        for (j=0;j<s;j++)
            printf("%d ",tra[i][j]);
        printf("\n");
    }
    for (i=0,br=0;i<s;i++)
        {
            for(j=0;j<s;j++)
                if (mat[i][j]!=tra[j][i])
                {
                    br=1;
                    printf("\nThe entered matrix is NOT a SYMMETRIC matrix.\n");
                    break;
                }
            if (br==1)
                break;
        }
    if (br==0)
        printf("\nThe entered matrix is a SYMMETRIC matrix.\n");
    return 0;
}
