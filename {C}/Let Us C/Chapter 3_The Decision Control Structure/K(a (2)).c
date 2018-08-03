#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    printf("Enter an CHARACTER:");
    scanf("%c",&ch);
    ch>=97 && ch<=122 ? printf("\nLOWER CASE ALPHABET.\n") : printf("\nNOT a LOWER CASE ALPHABET.\n");
    return 0;
}
