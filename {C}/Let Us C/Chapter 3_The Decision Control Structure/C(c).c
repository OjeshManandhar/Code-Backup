#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    printf("Enter a year: ");
    scanf("%d",&a);
    if (a%4==0)
        printf("\nThe year %d is a Leap Year.\n",a);
    else
        printf("\nThe year %d is NOT a Leap Year.\n",a);
    return 0;
}
