#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,j;
    for (i=1;i<=5;i++,printf("\n"))
        for (j=1;j<=i;j++)
            printf("%d",j);
    return 0;
}
