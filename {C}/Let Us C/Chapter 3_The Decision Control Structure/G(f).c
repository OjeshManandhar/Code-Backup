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
    {
        if (a==b && a==c)
            printf("\nThe triangle is EQUILATERAL.\n");
        else if (a==b || b==c || c==a)
            printf("\nThe triangle is ISOSCELES.\n");
        else if (l*l==(a*a+b*b+c*c-l*l))
            printf("\nIt is a RIGHT ANGLED TRIANGLE.\n");
        else
            printf("\nThe triangle is SCALENE.\n");
    }
    else
        printf("\nThe given sides can't form a triangle.\n");
    return 0;
}
