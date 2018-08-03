#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    printf("Enter a number: ");
    scanf("%d",&a);
    if (a%5==0 && a%11!=0)
        printf("\n%d is divisible by 5 but not by 11.\n",a);
    else if (a%11==0 && a%5!=0)
        printf("\n%d is divisible by 11 but not by 5.\n",a);
    else if (a%11==0 && a%5==0)
        printf("\n%d is divisible by both 5 and 11.\n",a);
    else
        printf("\n%d is not divisible by both 5 and 11.\n",a);
    return 0;
}
