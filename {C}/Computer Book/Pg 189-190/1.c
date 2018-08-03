#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n[10],i;
    for (i=0;i<10;i++)
    {
        printf("Enter number no.%d: ",i+1);
        scanf("%d",&n[i]);
    }
    printf("\nThe entered number in reverse order are:\n");
    for (i=9;i>=0;i--)
        printf("%d ",n[i]);
    return 0;
}
