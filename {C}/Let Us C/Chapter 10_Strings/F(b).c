#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <swap.h>

int main()
{
    char **name;
    int i,n,j;
    printf("Enter the number of names to sort: ");
    scanf("%d",&n);
    name=(char **)malloc(n*sizeof(char *));
    for (i=0;i<n;i++)
        name[i]=(char *)malloc(50*sizeof(char));
    printf("\n");
    for (i=0;i<n;i++)
    {
        fflush(stdin);
        printf("Enter the name no.%d: ",i+1);
        gets(name[i]);
    }
    printf("\nThe order in which you have entered the name is:\n");
    for (i=0;i<n;i++)
        puts(name[i]);
    for (i=0;i<n;i++)
        for (j=i+1;j<n;j++)
            if (strcmp(name[i],name[j])>0)
                swaps(name[i],name[j]);
    printf("\nThe ascending order of the names which you have entered:\n");
    for (i=0;i<n;i++)
        puts(name[i]);
    return 0;
}
