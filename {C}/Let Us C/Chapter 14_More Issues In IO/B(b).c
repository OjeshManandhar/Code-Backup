#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#include <strtoint.h>

int main(int argc, char *argv[])
{
    int n,m;
    if (argc!=4)
    {
        puts("Not enough arguments.");
        exit(EXIT_FAILURE);
    }
    n=sint(argv[2]);
    m=sint(argv[3]);
    if (strcmp(argv[1],"X")==0 || strcmp(argv[1],"x")==0)
        printf("%d * %d = %d\n",n,m,n*m);
    else if (strcmp(argv[1],"+")==0)
        printf("%d + %d = %d\n",n,m,n+m);
    else if (strcmp(argv[1],"/")==0)
    {
        printf("%d / %d = %d\n",n,m,n/m);
        printf("%d / %d = %d\n",m,n,m/n);
    }
    else if (strcmp(argv[1],"-")==0)
    {
        printf("%d - %d = %d\n",n,m,n-m);
        printf("%d - %d = %d\n",m,n,m-n);
    }
    else if (strcmp(argv[1],"%")==0)
    {
        printf("%d %c %d = %d\n",n,'%',m,n%m);
        printf("%d %c %d = %d\n",m,'%',n,m%n);
    }
    else if (strcmp(argv[1],"^")==0)
    {
        printf("%d ^ %d = %d\n",n,m,(int)pow(n,m));
        printf("%d ^ %d = %d\n",m,n,(int)pow(m,n));
    }
    else if (strcmp(argv[1],"==")==0)
        if (n==m)
            printf("%d == %d is TRUE\n",n,m);
        else
            printf("%d == %d is FALSE\n",n,m);
    else if (strcmp(argv[1],"!=")==0)
        if (n!=m)
            printf("%d != %d is TRUE\n",n,m);
        else
            printf("%d != %d is FALSE\n",n,m);
    else if (strcmp(argv[1],"<=")==0)
        if (n<=m)
            printf("%d <= %d is TRUE\n",n,m);
        else if (m<=n)
            printf("%d <= %d is TRUE\n",m,n);
        else
            puts("FALSE");
    else if (strcmp(argv[1],">=")==0)
        if (n>=m)
            printf("%d >= %d is TRUE\n",n,m);
        else if (m>=n)
            printf("%d >= %d is TRUE\n",m,n);
        else
            puts("FALSE");
    else if (strcmp(argv[1],"<")==0)
        if (n<m)
            printf("%d < %d is TRUE\n",n,m);
        else if (m<=n)
            printf("%d < %d is TRUE\n",m,n);
        else
            puts("FALSE");
    else if (strcmp(argv[1],">")==0)
        if (n>m)
            printf("%d > %d is TRUE\n",n,m);
        else if (m>=n)
            printf("%d > %d is TRUE\n",m,n);
        else
            puts("FALSE");
    else
        puts("Wrong Switch");
    return 0;
}
