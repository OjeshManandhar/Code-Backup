#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    printf("Enter an integer: ");
    scanf("%d",&a);
    if (a%3==0 && a%5==0)
        printf("\n%d is divisible by 3 and 5.\n",a);
    else
        printf("\n%d is not divisible by 3 and 5.\n",a);
    return 0;
}
