#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <swap.h>

int main()
{
    char **n;
    int x,i,j;
    printf("Enter the number of students which you want to sort: ");
    scanf("%d",&x);
    n=(char **)malloc(x*sizeof(char *));
    for (i=0;i<x;i++)
        n[i]=(char *)malloc(50*sizeof(char));
    for (i=0;i<x;i++)
    {
        fflush(stdin);
        printf("Enter the name of student no.%d: ",i+1);
        gets(n[i]);
    }
    printf("\nThe order in which you have entered the name is:\n");
    for (i=0;i<x;i++)
        puts(n[i]);
    for (i=0;i<x;i++)
        for (j=i+1;j<x;j++)
            if(strcmp(n[i],n[j])<0)
                swaps(n[i],n[j]);
    printf("\nThe descending order of the names which you have entered:\n");
    for (i=0;i<x;i++)
        puts(n[i]);
    return 0;
}
