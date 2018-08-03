#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <upper.h>

int main()
{
    int i,len,p,c,flag=0;
    char n[100],*ln,*ch;
    printf("Enter your name [MAX 99 CHARACTERS]: ");
    gets(n);
    len=strlen(n)+1;
    ln=(char *)malloc(len*sizeof(char));
    ch=(char *)malloc(len*sizeof(char));
    for (i=0;i<len-1;i++)
        if (n[i]==' ')
        {
            flag=1;
            p=i;
        }
    if (flag==0)
    {
        ln[0]=cupr(n[0]);
        for (i=1;i<len-1;i++)
            ln[i]=n[i];
        ln[i]=0;
        printf("\nThe abbreviate of your name is: ");
        puts(ln);
        return 0;
    }
    ln[0]=cupr(n[p+1]);
    for (i=p+2,c=1;i<len;i++,c++)
        ln[c]=n[i];
    ln[c]=0;
    ch[0]=cupr(n[0]);
    ch[1]='.';
    ch[2]=' ';
    for (i=1,c=3;i<p-1;i++)
        if (n[i]==' ')
        {
            ch[c]=cupr(n[i+1]);
            ch[c+1]='.';
            ch[c+2]=' ';
            c+=3;
        }
    ch[c]=0;
    strcat(ch,ln);
    printf("\nThe abbreviate of your name is: ");
    puts(ch);
    return 0;
}
