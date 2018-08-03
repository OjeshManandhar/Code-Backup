#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c;
    printf("Enter the 3 angles of the triangle [SEPERATED BY A TAB]: ");
    scanf("%f%f%f",&a,&b,&c);
    if (a+b+c==180.0)
        printf("\nThe triangle is VALID.\n");
    else
        printf("\nThe triangle is NOT VALID.\n");
    return 0;
}
