#include <stdio.h>
#include <stdlib.h>

int main()
{
    float l,b,a,p;
    printf("Enter the Length of the rectangle: ");
    scanf("%f",&l);
    printf("Enter the Breadth of the rectangle: ");
    scanf("%f",&b);
    p=2*(l+b);
    a=l*b;
    if (a>p)
        printf("\nArea of this rectangle is Greater than its Perimeter.\n");
    else if (p>a)
        printf("\nArea of this rectangle is Smaller than its Perimeter.\n");
    else
        printf("\nThe Area and Perimeter of this rectangle are Equal.\n");
    return 0;
}
