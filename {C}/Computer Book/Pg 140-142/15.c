#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a ;
    printf("Enter age: ");
    scanf("%d",&a);
    if (a<0)
        printf("\nError\nWrong Entry.\n");
    else if (a<=10)
        printf("\nHe/She is a CHILD.\n");
    else if (a<=20)
        printf("\nHe/She is a TEENAGE.\n");
    else if (a<=30)
        printf("\nHe/She is a YOUNG.\n");
    else if (a<=45)
        printf("\nHe/She is a ADULT.\n");
    else
        printf("\nHe/She is a OLD.\n");
    return 0;
}
