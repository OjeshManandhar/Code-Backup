#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100];
    int i;
    printf("Enter a sentence: ");
    gets(s);
    for (i=0;i<strlen(s);i++)
        if (s[i]==' ')
            s[i]='-';
    printf("\nThe entered sentence when spaces are replaced with hyphen:\n");
    puts(s);
    return 0;
}
