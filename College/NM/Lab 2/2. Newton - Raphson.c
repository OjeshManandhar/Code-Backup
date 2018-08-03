#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x) (x*x*x - 2*x - 5)
#define G(x) (3*x*x - 2)

#define decimal_place 0.0001

int main()
{
    int i = 1;
    float x, x0, temp_x0;

    printf("Enter value for x: ");
    scanf("%f", &x);

    x0 = temp_x0 = x - F(x)/G(x);

    printf("\n%-2s %c %-10s %c %-10s %c %-10s %c %-10s\n", "SN", 179, "x", 179, "F(x)", 179, "G(x)", 179, "x0");
    printf("%-2d %c %10.5f %c %10.5f %c %10.5f %c %10.5f\n", i++, 179, x, 179, F(x), 179, G(x), 179, x0);

    while (1)
    {
        x = x0;

        x0 = x - F(x)/G(x);

        printf("%-2d %c %10.5f %c %10.5f %c %10.5f %c %10.5f\n", i++, 179, x, 179, F(x), 179, G(x), 179, x0);

        if (fabs(temp_x0 - x0) > decimal_place)
            temp_x0 = x0;
        else
            break;
    }

    printf("\nAnswer: %.3f\n", x0);

    return 0;
}
