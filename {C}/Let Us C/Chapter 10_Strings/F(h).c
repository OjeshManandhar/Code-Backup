#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <extract.h>
#include <upper.h>

int main()
{
    int i,c,len;
    char n[100],*e,*ch;
    printf("Enter a sentence: ");
    gets(n);
    len=strlen(n)+1;
    ch=(char *)malloc(len*sizeof(char));
    len--;
    if (len<3)
    {
        printf("\nThe entered sentence without the word the is [IF GRAMMATICALLY CORRECT]:\n");
        puts(n);
        return 0;
    }
    else if (len==3)
    {
        e=supr(n);
        printf("\nThe entered sentence without the word the is [IF GRAMMATICALLY CORRECT]:\n");
        if (strcmp(e,"THE")!=0)
            puts(n);
        else
            printf("%c\n",n[3]);
        return 0;
    }
    else if (len==4)
    {
        printf("\nThe entered sentence without the word the is [IF GRAMMATICALLY CORRECT]:\n");
        e=supr(n);
        if (strcmp(e,"THE ")==0)
            printf("%c%c\n",n[3],n[4]);
        else
            puts(n);
        return 0;
    }
    else if (len>4)
    {
        e=left(n,4);
        e=supr(e);
        if (strcmp(e,"THE ")!=0)
        {
            ch[0]=n[0];
            c=i=1;
        }
        else
        {
            ch[0]=n[3];
            c=1;
            i=3;
        }
        for (;i<len;i++)
        {
            e=mid(n,i,5);
            e=supr(e);
            if (strcmp(e," THE ")==0)
            {
                ch[c]=n[i];
                ch[c+1]=n[i+4];
                c+=2;
                i+=3;//one aafai loopko i++le garda badxa|
            }
            else
            {
                ch[c]=n[i];
                c++;
            }
        }
    }
    ch[c]=0;
    printf("\nThe entered sentence without the word the is [IF GRAMMATICALLY CORRECT]:\n");
    puts(ch);
    return 0;
}
