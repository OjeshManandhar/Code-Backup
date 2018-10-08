#include <stdio.h>
#include <stdlib.h>

void display(double **coeffiicient, double **inverse, const unsigned int n)
{
    unsigned int i, j;

    printf("\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%10.3lf ", coeffiicient[i][j]);

        printf(": ");

        for (j = 0; j < n; j++)
            printf("%10.3lf ", inverse[i][j]);

        printf("\n");
    }

    printf("\n");
}

int main()
{
    unsigned int n;
    int i, j, k;
    double **coefficient = NULL, **inverse = NULL;
    double temp;

    printf("Enter the number of equations: ");
    scanf("%u", &n);

    coefficient = (double **)calloc(n ,sizeof(double *));
    for (i = 0; i < n; i++)
        coefficient[i] = (double *)calloc(n, sizeof(double));

    inverse = (double **)calloc(n ,sizeof(double *));
    for (i = 0; i < n; i++)
        inverse[i] = (double *)calloc(n, sizeof(double));

    for (i = 0; i < n; i++)
    {
        printf("\nEnter element for %d row:\n", i + 1);

        for (j = 0; j < n; j++)
        {
            printf("Enter %d element: ", j + 1);
            scanf("%lf", &coefficient[i][j]);
        }
    }

    for (i = 0; i < n; i++)
        inverse[i][i] = 1;

    display(coefficient, inverse, n);

    for (i = 0; i < n; i++)
    {
        temp = coefficient[i][i];

        for (j = 0; j < n; j++)
        {
            coefficient[i][j] /= temp;
            inverse[i][j] /= temp;
        }
        coefficient[i][i] = 1;

        for (j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            temp = coefficient[j][i];

            for (k = 0; k < n; k++)
            {
                if (k == i)
                    coefficient[j][k] = 0;
                    //this is used because the result of below calculation of coefficient[j][k]
                    //gave some value of range 10^-7 which showed -0.0 while displaying
                else
                    coefficient[j][k] -= temp*coefficient[i][k];

                inverse[j][k] -= temp*inverse[i][k];
            }

            display(coefficient, inverse, n);
        }
    }

    printf("The inverse is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%10.5lf ", inverse[i][j]);
        printf("\n");
    }

    return 0;
}
