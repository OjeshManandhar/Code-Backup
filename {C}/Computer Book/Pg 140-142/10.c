#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c;
    printf("Enter any 3 numbers [SEPERATED BY A TAB]: ");
    scanf("%f%f%f",&a,&b,&c);
    if (a<b && a<c)
        printf("\n%.2f is the smallest.\n",a);
    else if (b<a && b<c)
        printf("\n%.2f is the smallest.\n",b);
    else if (c<a && b>c)
        printf("\n%.2f is the smallest.\n",c);
    return 0;
}
