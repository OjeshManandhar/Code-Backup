#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    printf("Enter an integer: ");
    scanf("%d",&a);
    if (a%7==0)
        printf("\n%d is a multiple of 7.\n",a);
    else
        printf("\n%d is not a multiple of 7.\n",a);
    return 0;
}
