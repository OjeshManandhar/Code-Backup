#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    printf("Enter an integer: ");
    scanf("%d",&a);
    if (a%2==0)
        printf("\nThe number %d is EVEN.\n",a);
    else
        printf("\nThe number %d is ODD.\n",a);
    return 0;
}
