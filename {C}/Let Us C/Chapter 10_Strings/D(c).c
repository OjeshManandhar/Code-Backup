#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char *str,s[100];
    int p,n,i,x=0,len;
    printf("Enter a string: ");
    gets(s);
    len=strlen(s);
    printf("Enter the position to extract from: ");
    scanf("%d",&p);
    if (p>len)
    {
        printf("Invalid Entry.\n");
        exit(1);
    }
    p--;
    printf("Enter number of character to extract: ");
    scanf("%d",&n);
    if (p+n-1>len)
    {
        printf("Invalid Entry.\n");
        exit(1);
    }
    str=(char *)malloc(n+1);
    n--;
    for (i=p;i<=p+n;i++,x++)
        str[x]=s[i];
    str[x]=0;
    printf("\nExtracted characters are: ");
    puts(str);
    return 0;
}
