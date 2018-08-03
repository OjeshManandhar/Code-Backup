#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0;
    printf("Value \t Character\n");
    while (i<=255)
    {
        printf("%d \t %c\n",i,i);
        i++;
    }
    return 0;
}
