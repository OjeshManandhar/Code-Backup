#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100],c;
    int i,o=0;
    printf("Enter a character: ");
    scanf("%c",&c);
    if (c>='A' && c<='Z')
        c+=32;
    fflush(stdin);
    printf("Enter a sentence: ");
    gets(s);
    for (i=0;i<strlen(s);i++)
        if (s[i]==c || s[i]==c-32)
            o++;
    printf("\nTotal number of occurrence of %c/%c is %d.\n",c,c-32,o);
    return 0;
}
