#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <strtoint.h>

#define BACKWARD
//#undef BACKWARD

float getfloat(const char *ch)
{
    int i=0,l,f=0,x=0;
    float y=0;
    l=strlen(ch);
    while (ch[i]!='.')
    {
        x=x*10+cint(ch[i]);
        i++;
        if (i==l)
            return x*1.0;
    }
    #ifdef BACKWARD
        int j;
        for (j=l-1;j>i;j--)
            y=y/10.0+cint(ch[j])/10.0;
    #else
        int c=1.0;
        for (i++;i<l;i++,c*=10.0)
            y=y*10.0+cint(ch[i]);
        y/=c;
    #endif // BACKWARD
    return (x+y);
}

int main()
{
    char ch[25];
    printf("Enter a float: ");
    gets(ch);
    printf("\nThe float you entered is: %f.\n",getfloat(ch));
    return 0;
}
