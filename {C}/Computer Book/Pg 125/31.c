#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    printf("Enter a character: ");
    scanf("%c",&ch);
    printf("\nThe ASCII code of \"%c\" is %d.\n",ch,ch);
    return 0;
}
