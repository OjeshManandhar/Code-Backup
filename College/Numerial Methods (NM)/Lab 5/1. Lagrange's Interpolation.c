#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int i, j, n;
    double m, product, sum;
    double *x = NULL, *y = NULL;

    printf("Enter number of data set: ");
    scanf("%u", &n);

    x = (double *)calloc(n, sizeof(double));
    y = (double *)calloc(n, sizeof(double));

    printf("\nEnter the data sets\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter x[%u]: ", i + 1);
        scanf("%lf", &x[i]);

        printf("Enter y[%u]: ", i + 1);
        scanf("%lf", &y[i]);

        printf("\n");
    }

    printf("Enter point to be estimated: ");
    scanf("%lf", &m);

    sum = 0;
    for (i = 0; i < n; i++)
    {
        for (product = 1, j = 0; j < n; j++)
            if (i == j)
                continue;
            else
                product *= (m - x[j])/(x[i] - x[j]);

        sum += y[i]*product;
    }

    printf("\n\nAnswer, f[%.3f] = %.3f\n", m, sum);

    free(x);
    free(y);

    return 0;
}
