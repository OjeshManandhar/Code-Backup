#include <stdio.h>
#include <stdlib.h>

int main()
{
    int op,n,f,i;
    while (1)
    {
        printf("Choose an Option.\n");
        printf("(1) Factorial of a number.\n");
        printf("(2) Prime or not.\n");
        printf("(3) Odd or even.\n");
        printf("(4) Exit.\n");
        printf("Enter the choice [OPTION NUMBER]: ");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            f=1;
            printf("Enter the number: ");
            scanf("%d",&n);
            for (i=1;i<=n;i++)
                f*=i;
                    printf("Factorial is: %d.\n\n",f);
            break;
        case 2:
            f=0;
            printf("Enter the number: ");
            scanf("%d",&n);
            for (i=1;i<=n;i++)
                if (n%i==0)
                    f++;
            if (f<=2)
                printf("The number is Prime Number.\n\n");
            else
                printf("The number is not a Prime Number.\n\n");
            break;
        case 3:
            printf("Enter the number: ");
            scanf("%d",&n);
            if (n%2==0)
                printf("The number is Even Number.\n\n");
            else
                printf("The number is Odd Number.\n\n");
            break;
        case 4:
            exit(1);
        }
    }
    return 0;
}
