#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c='y';
    float n;
    while (c=='y' || c=='Y')
    {
        printf("Enter a number: ");
        scanf("%f",&n);
        if (n>0)
            printf("The entered number is POSITIVE.\n\n");
        else if (n<0)
            printf("The entered number is NEGATIVE.\n\n");
        else
            printf("The entered number is ZERO.\n\n");
        printf("Do you want to continue [Y/N]: ");
        fflush(stdin);
        scanf("%c",&c);
        if (c=='y' || c=='Y')
            printf("\n");
        else if (c=='n' || c=='N')
            printf("PROGRAM TERMINATED.\n");
        else
            printf("WRONG option. PROGRAM TERMINATED.\n");
    }
    return 0;
}
