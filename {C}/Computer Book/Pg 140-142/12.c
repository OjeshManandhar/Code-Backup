#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c,d;
    printf("Enter any 4 numbers: ");
    scanf("%f%f%f%f",&a,&b,&c,&d);
    if (a>b && a>c && a>d)
        printf("\n%.2f is GREATEST.\n",a);
    else if (b>a && b>c && b>d)
        printf("\n%.2f is GREATEST.\n",b);
    else if (c>a && c>b && c>d)
        printf("\n%.2f is GREATEST.\n",c);
    else if (d>a && d>b && d>c)
        printf("\n%.2f is GREATEST.\n",d);
    if (a<b && a<c && a<d)
        printf("%.2f is SMALLEST.\n",a);
    else if (b<a && b<c && b<d)
        printf("%.2f is SMALLEST.\n",b);
    else if (c<a && c<b && c<d)
        printf("%.2f is SMALLEST.\n",c);
    else if (d<a && d<b && d<c)
        printf("%.2f is SMALLEST.\n",d);
    return 0;
}
