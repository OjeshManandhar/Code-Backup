#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    printf("Enter a Character: ");
    scanf("%c",&ch);
    if (ch>=65 && ch<=90)
        printf("\nThe character (%c) is a UPPER CASE LETTER.\n",ch);
    else if (ch>=97 && ch<=122)
        printf("\nThe character (%c) is a SMALL CASE LETTER.\n",ch);
    else if (ch>=48 && ch<=57)
        printf("\nThe character (%c) is a NUMBER.\n",ch);
    else
        printf("\nThe character (%c) is a SPECIAL CHARACTER.\n",ch);
    return 0;
}
