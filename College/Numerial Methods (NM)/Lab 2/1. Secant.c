#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x) (x*x*x - 2*x - 5)
#define decimal_place 0.0001

int main()
{
    int i = 1;
    float x1, x2, x0, temp_x0;

    printf("Enter values for x1 & x2 [SEPARATED BY A TAB]: ");
    scanf("%f%f", &x1, &x2);

    x0 = temp_x0 = x1 - (F(x1)*(x2 - x1))/(F(x2) - F(x1));

    printf("\n%-2s %c %-10s %c %-10s %c %-10s %c %-10s %c %-10s\n", "SN", 179, "x1", 179, "x2", 179, "F(x1)", 179, "F(x2)", 179, "x0");
    printf("%-2d %c %10.5f %c %10.5f %c %10.5f %c %10.5f %c %10.5f\n", i++, 179, x1, 179, x2, 179, F(x1), 179, F(x2), 179, x0);

    while (1)
    {
        x1 = x2;
        x2 = x0;

        x0 = x1 - (F(x1)*(x2 - x1))/(F(x2) - F(x1));

        printf("%-2d %c %10.5f %c %10.5f %c %10.5f %c %10.5f %c %10.5f\n", i++, 179, x1, 179, x2, 179, F(x1), 179, F(x2), 179, x0);

        if (fabs(temp_x0 - x0) > decimal_place)
            temp_x0 = x0;
        else
            break;
    }

    printf("\nAnswer: %.3f\n", x0);

    return 0;
}
