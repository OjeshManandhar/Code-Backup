#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=1,j=1;
    for(;i<=25;i++,j=1)
    {
        for(;j<=79;j++)
            printf("%c",1);
        printf("\n");
    }
    return 0;
}
