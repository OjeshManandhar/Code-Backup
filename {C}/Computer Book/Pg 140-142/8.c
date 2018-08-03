#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    printf("Enter a year: ");
    scanf("%d",&a);
    if (a%4==0)
        printf("\n%d is a leap year.\n",a);
    else
        printf("\n%d is not a leap year.\n",a);
    return 0;
}
