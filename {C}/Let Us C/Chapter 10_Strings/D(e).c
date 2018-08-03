#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char *x[5],*f[5]={"a","b"},*p;
    int i,len;
    printf("%s\t%s\t",f[0],f[1]);
    for (i=2;i<5;i++)
    {
        x[i-2]=f[i-2];
        x[i-1]=f[i-1];
        f[i]=f[i-1];
        f[i-1]=f[i-2];
        len=strlen(f[i])+strlen(f[i-1])+1;
        p=(char *)malloc(len);
        strcpy(p,f[i]);
        strcat(p,f[i-1]);
        printf("%s\t",p);
        f[i-1]=x[i-1];
        f[i]=p;
    }
    return 0;
}
