#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char);

int main()
{
    char n[80],e[80];
    int i,c=0;
    printf("Enter a sentence: ");
    gets(n);
    puts(n);
    for (i=0;i<strlen(n);i++)
        if (check(n[i])!=1)
        {
            e[c]=n[i];
            c++;
        }
    printf("\nThe entered sentence without vowels is: \n");
    puts(e);
    return 0;
}

int check(char c)
{
    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
        return 1;
    return 0;
}
