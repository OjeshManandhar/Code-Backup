#include <stdio.h>
#include <stdlib.h>

void hcheck(int mat[9][9],int);
void vcheck(int mat[9][9],int);
void boxcheck(int mat [9][9],int,int);
void check(int br);
int main()
{
    int puzzle[9][9]={
                        5,3,4,6,7,8,9,1,2,
                        6,7,2,1,9,5,3,4,8,
                        1,9,8,3,4,2,5,6,7,
                        8,5,9,7,6,1,4,2,3,
                        4,2,6,8,5,3,7,9,1,
                        7,1,3,9,2,4,8,5,6,
                        9,6,1,5,3,7,2,8,4,
                        2,8,7,4,1,9,6,3,5,
                        3,4,5,2,8,6,1,7,9
                     },i,j,br=0;
    for (i=0;i<9;i++)
    {
        hcheck(puzzle,i);
        vcheck(puzzle,i);
    }
    for (i=0;i<9;i+=3)
        for (j=0;j<9;j+=3)
            boxcheck(puzzle,i,j);
    printf("Correct.\n");
    return 0;
}

void check(int br)
{
    if (br==1)
    {
        printf("Incorrect.\n");
        exit(1);
    }
}
void hcheck(int mat[9][9],int i)
{
    int n[9],x,y,br=0;
    mat[0][0]=n[0];
    for (x=1;x<9;x++)
        for (y=0;y<x;y++)
        {
            if (mat[i][x]==n[y])
                br=1;
            else
                n[x]=mat[i][x];
            check(br);
        }
}

void vcheck(int mat[9][9],int i)
{
    int n[9],x,y,br=0;
    mat[0][0]=n[0];
    for (x=1;x<9;x++)
        for (y=0;y<x;y++)
        {
            if (mat[x][i]==n[y])
                br=1;
            else
                n[x]=mat[x][i];
            check(br);
        }
}

void boxcheck(int mat[9][9],int i,int j)
{
    int n[9],x,y,z,c=1,br=0;
    mat[i][j]=n[0];
    for (x=i;x<i+3;x++)
        for (y=j;y<j+3;y++,c++)
            if (x!=i || y!=j)
                for (z=0;z<c;z++)
                {
                    if (mat[x][y]==n[z])
                        br=1;
                    else
                        n[c]=mat[x][y];
                    check(br);
                }
}
