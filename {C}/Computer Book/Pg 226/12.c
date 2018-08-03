#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int);

int main()
{
    int i;
    for (i=1;i<=10;i++)
        print(i);
    return 0;
}

void print(int a)
{
    printf("%d\t",a*a);
}
