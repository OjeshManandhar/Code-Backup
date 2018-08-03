#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c,l;
    printf("Enter the length of 3 sides of the triangle [SEPERATED BY A TAB]: ");
    scanf("%f%f%f",&a,&b,&c);
    if (a>b && a>c)
        l=a;
    else if (b>a && b>c)
        l=b;
    else if (c>a && b<c)
        l=c;
    if ((a+b+c-l)>l)
        printf("\nThe triangle is VALID.\n");
    else
        printf("\nThe triangle is NOT VALID.\n");
    return 0;
}
