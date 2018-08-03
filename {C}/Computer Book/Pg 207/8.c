#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[50],*rev;
    int i,len,c=0;
    printf("Enter a string: ");
    gets(str);
    len=strlen(str);
    rev=(char *)malloc(len+1);
    for(i=len-1;i>=0;i--,c++)
        rev[c]=str[i];
    rev[i]=0;
    printf("\nThe reverse string in reverse order is:\n");
    puts(rev);
    return 0;
}
