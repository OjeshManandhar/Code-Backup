#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=1,n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("\n");
    for (;i<=10;i++)
        printf("%d X %d = %d\n",n,i,n*i);
    return 0;
}
