#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    int n,f,i;
    float x;
    printf("Choose an option:\n");
    printf("a. Factorial of a number.\n");
    printf("b. Prime or not.\n");
    printf("c. Odd or Even.\n");
    printf("d. Multiplication table.\n");
    printf("e. Exit.\n");
    printf("Enter your choice: ");
    scanf("%c",&c);
    switch (c)
    {
    case 'a': case 'A':
        printf("\na. Factorial of a number.\n\n");
        f=1;
        printf("Enter a number: ");
        scanf("%d",&n);
        for (i=1;i<=n;i++)
            f*=i;
        printf("\nFactorial of %d is %d.\n",n,f);
        break;
    case 'b': case 'B':
        printf("\nb. Prime or not.\n\n");
        f=0;
        printf("Enter a number: ");
        scanf("%d",&n);
        for (i=1;i<=n;i++)
            if(n%i==0)
                f++;
        if (f<=2)
            printf("\n%d is a Prime number.\n",n);
        else
            printf("\n%d is not a Prime number.\n",n);
        break;
    case 'c': case 'C':
        printf("\nc. Odd or Even.\n\n");
        printf("Enter a number: ");
        scanf("%d",&n);
        if (n%2==0)
            printf("\n%d is a Even number.\n",n);
        else
            printf("\n%d is a Odd number.\n",n);
        break;
    case 'd': case 'D':
        printf("\nd. Multiplication table.\n\n");
        printf("Enter a number: ");
        scanf("%f",&x);
        for (i=1;i<=10;i++)
            printf("%d * %.2f = %.2f\n",i,x,i*x);
        break;
    }
    return 0;
}
