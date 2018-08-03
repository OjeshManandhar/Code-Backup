#include <stdio.h>
#include <math.h>

#define F(x) (x*x*x - 2*x - 5)
#define decimal_place 0.0001

#define FALSI

#ifdef BISECTION
    #define FORMULA ((x1 +x2)/2.0)
#endif

#ifdef FALSI
    #define FORMULA (x1 - (F(x1)*(x2 - x1))/(F(x2) - F(x1)))
#endif

int main()
{
    int i = 1;
    float x1, x2, x0, temp_x0;

    do
    {
        printf("Enter x1 and x2 [SEPARATED BY A TAB]: ");
        scanf("%f%f", &x1, &x2);
    }while (F(x1)*F(x2) > 0);

    x0 = temp_x0 = FORMULA;

    printf("\n%-2s %c %-8s %c %-8s %c %-8s %c %-8s %c %-8s %c %-8s\n", "SN", 179, "x1", 179, "x2", 179, "F(x1)", 179, "F(x2)", 179, "x0", 179, "F(x0)");
    printf("%-2d %c %8.5f %c %8.5f %c %8.5f %c %8.5f %c %8.5f %c %8.5f\n", i++, 179, x1, 179, x2, 179, F(x1), 179, F(x2), 179, x0, 179, F(x0));

    while (1)
    {
        if (F(x1)*F(x0) < 0)
            x2 = x0;
        else if (F(x2)*F(x0) < 0)
            x1 = x0;

        x0 = FORMULA;

        printf("%-2d %c %8.5f %c %8.5f %c %8.5f %c %8.5f %c %8.5f %c %8.5f\n", i++, 179, x1, 179, x2, 179, F(x1), 179, F(x2), 179, x0, 179, F(x0));

        if (fabs(temp_x0 - x0) > decimal_place)
            temp_x0 = x0;
        else
            break;
    }

    printf("\nAnswer: %.3f\n", x0);

    return 0;
}
