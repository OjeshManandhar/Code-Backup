#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int i, n;
    double x, y;
    double sum_x = 0, sum_y = 0, sum_x2 = 0, sum_xy = 0;
    double a, b;

    printf("Enter number of data set: ");
    scanf("%d", &n);

    printf("\nEnter the data sets\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter x[%u]: ", i + 1);
        scanf("%lf", &x);

        printf("Enter y[%u]: ", i + 1);
        scanf("%lf", &y);

        printf("\n");

        sum_x += x;
        sum_y += y;
        sum_x2 += x*x;
        sum_xy += x*y;
    }

    b = (n*sum_xy - sum_x*sum_y)/(n*sum_x2 - sum_x*sum_x);
    a = sum_y/n - b*sum_x/n;
    //a = (sum_y*sum_x2 - sum_x*sum_xy)/(n*sum_x2 - sum_x*sum_x);

    printf("The linear equation is: y = %.2f + %.2fx\n\n", a, b);

    return 0;
}
