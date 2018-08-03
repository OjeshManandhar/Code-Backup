#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,j,len;
    char n[50],*r;
    printf("Enter a string: ");
    gets(n);
    len=strlen(n);
    r=(char *)malloc(len+1);
    printf("\nRotating the letters/characters of the string:\n");
    for (i=0;i<len;i++)
    {
        for (j=0;j<len;j++)
            if (j==len-1)
                r[j]=n[0];
            else
                r[j]=n[j+1];
        puts(r);
        strcpy(n,r);
    }
    return 0;
}
