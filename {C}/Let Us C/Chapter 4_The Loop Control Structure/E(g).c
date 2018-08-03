#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,p,tc=1,d=0,t,b;
    printf("ABCDEFGFEDCBA\n");
    for (i=1;i<=6;i++)
    {
        p=65;
        for (j=1;j<=(7-i);j++,p++)
            printf("%c",p);
        for (t=1;t<=tc;t++)
            printf(" ");
        tc+=2;
        p=70-d;
        for (b=(7-i);b>=1;b--,p--)
            printf("%c",p);
        d++;
        printf("\n");
    }
    return 0;
}
