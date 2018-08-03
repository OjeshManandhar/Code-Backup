#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getint(const char *ch)
{
    char a;
    int i,l,x=0;
    l=strlen(ch);
    for (i=0;i<l;i++)
    {
        a=ch[i];
        if (a=='0')
            x=x*10+0;
        else if (a=='1')
            x=x*10+1;
        else if (a=='2')
            x=x*10+2;
        else if (a=='3')
            x=x*10+3;
        else if (a=='4')
            x=x*10+4;
        else if (a=='5')
            x=x*10+5;
        else if (a=='6')
            x=x*10+6;
        else if (a=='7')
            x=x*10+7;
        else if (a=='8')
            x=x*10+8;
        else if (a=='9')
            x=x*10+9;
    }
    return x;
}

int main()
{
    char ch[25];
    printf("Enter an integer: ");
    scanf("%s",ch);
    printf("\nYou entered: %d.\n",getint(ch));
    return 0;
}
