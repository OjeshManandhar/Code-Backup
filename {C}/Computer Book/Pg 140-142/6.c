#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    printf("Enter a character: ");
    scanf("%c",&c);
    if (c>='0' && c<='9')
        printf("\nThe entered character is a digit.\n");
    else
        printf("\nThe entered character is a character.\n");
    return 0;
}
