#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    printf("Enter 5-digit number: ");
    scanf("%d",&a);
    b=a+11111;
    printf("\nAdding 1 to each digit of the given number.\n");
    printf("The new number formed is: %d\n",b);
    return 0;
}
