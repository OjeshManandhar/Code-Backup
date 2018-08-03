#include <stdio.h>
#include <stdlib.h>

int main()
{
    float w;
    printf("Enter the weight of the boxer: ");
    scanf("%f",&w);
    if (w<115)
        printf("\nBoxer Class: Flyweight\n");
    else if (w>=115 && w<=121)
        printf("\nBoxer Class: Bantamweight\n");
    else if (w>=122 && w<=153)
        printf("\nBoxer Class: Featherweight\n");
    else if (w>=154 && w<=189)
        printf("\nBoxer Class: Middleweight\n");
    else
        printf("\nBoxer Class: Heavyweight\n");
    return 0;
}
