#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    float n;
    printf("Enter the number of which you want to generate multiplication table: ");
    scanf("%f",&n);
    for (i=1;i<=10;i++)
        printf("%.2f * %d = %.2f\n",n,i,n*i);
    return 0;
}
