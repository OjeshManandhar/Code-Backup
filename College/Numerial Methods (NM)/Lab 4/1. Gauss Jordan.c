#include <stdio.h>
#include <stdlib.h>

void display(double **coeffiicient, double *constant, const unsigned int n)
{
    unsigned int i, j;

    printf("\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%10.3lf ", coeffiicient[i][j]);

        printf(": %10.3lf\n", constant[i]);
    }

    printf("\n");
}

int main()
{
    unsigned int n;
    int i, j, k;
    double **coefficient = NULL, *constant = NULL;
    double temp;

    printf("Enter the number of equations: ");
    scanf("%u", &n);

    constant = (double *)calloc(n ,sizeof(double));
    coefficient = (double **)calloc(n ,sizeof(double *));
    for (i = 0; i < n; i++)
        coefficient[i] = (double *)calloc(n, sizeof(double));

    for (i = 0; i < n; i++)
    {
        printf("\nEnter the coefficients and constant of %d equation:\n", i + 1);
        for (j = 0; j < n; j++)
        {
            printf("Enter %d coefficient: ", j + 1);
            scanf("%lf", &coefficient[i][j]);
        }
        printf("Enter constant of %d equation: ", i + 1);
        scanf("%lf", &constant[i]);
    }

    display(coefficient, constant, n);

    for (i = 0; i < n; i++)
    {
        temp = coefficient[i][i];

        for (j = i; j < n; j++)
            coefficient[i][j] /= temp;
        constant[i] /= temp;
        coefficient[i][i] = 1;

        for (j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            temp = coefficient[j][i];

            for (k = 0; k < n; k++)
                if (k == i)
                    coefficient[j][k] = 0;
                    //this is used because the result of below calculation of coefficient[j][k]
                    //gave some value of range 10^-7 which showed -0.0 while displaying
                else
                    coefficient[j][k] -= temp*coefficient[i][k];
            constant[j] -= temp*constant[i];

            display(coefficient, constant, n);
        }
    }

    printf("The roots are:\n");
    for (i = 0; i < n - 1; i++)
        printf("%.5lf, ", constant[i]);
    printf("\b\b & %.5lf\n", constant[i]);

    return 0;
}
