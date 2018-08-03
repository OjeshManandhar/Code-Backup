#include <stdio.h>
#include <stdlib.h>

int main()
{
    int y;
    float x;
    printf("    i=2+(y+0.5x)\n\n");
    printf("x\t y\t i\n");
    for (y=1;y<=6;y++)
    {
        for (x=5.5;x<=12.5;x+=0.5)
            printf("%d\t%.2f\t%.1f\n",y,x,2+(y+0.5*x));
        printf("\n");
    }
    return 0;
}
