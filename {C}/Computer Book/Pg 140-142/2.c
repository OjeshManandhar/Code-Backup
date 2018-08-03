#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    printf("Enter the age: ");
    scanf("%d",&a);
    if (a>=18)
        printf("\nHe/She is eligible to vote.\n");
    else
        printf("\nHe/She is not eligible to vote.\n");
    return 0;
}
