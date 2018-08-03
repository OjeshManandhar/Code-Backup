#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n;
    printf("Enter the number of terms of the series: ");
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        printf("%d ",i*i);
    return 0;
}
