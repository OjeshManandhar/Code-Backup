#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100],*c;
    int i,o=0;
    printf("Enter a sentence: ");
    gets(s);
    c=(char *)malloc(strlen(s)+1);
    for (i=strlen(s)-1;i>=0;i--,o++)
        c[o]=s[i];
    c[o]=0;
    printf("\nThe entered string in reverse order is: %s",c);
    return 0;
}
