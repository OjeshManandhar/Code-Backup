#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100];
    int i,l,v,c,b,w;
    l=v=c=b=w=0;
    printf("Enter a sentence: ");
    gets(s);
    for (i=0;i<strlen(s);i++)
    {
        if (s[i]==' ')
            b++;
        else if ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
            l++;
        if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            v++;
    }
    printf("\nTotal number of letters: %d.\n",l);
    printf("Total number of vowels: %d.\n",v);
    printf("Total number of consonants: %d.\n",l-v);
    printf("Total number of words: %d.\n",b+1);
    printf("Total number of blank spaces: %d.\n",b);
    return 0;
}
