#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n;
    int x;
    char c;
    printf("Choose a option:\n");
    printf("(a). Positive or Negative.\n");
    printf("(b). Even or Odd.\n");
    printf("(c). Exit.\n");
    printf("Enter your choice: ");
    scanf("%c",&c);
    switch (c)
    {
    case 'a': case 'A':
        printf("\n(a). Positive or Negative.\n");
        printf("Enter a number: ");
        scanf("%f",&n);
        if (n>0)
            printf("\nThe number %.2f is Positive.\n",n);
        else if (n<0)
            printf("\nThe number %.2f is Negative.\n",n);
        else
            printf("\nThe number %.2f is Zero.\n",n);
        break;
    case 'b': case 'B':
        printf("\n(b). Even or Odd.\n");
        printf("Enter a number: ");
        scanf("%d",&x);
        if (x%2==0)
            printf("\nThe number %d is Even.\n",x);
        else
            printf("\nThe number %d is Odd.\n",x);
        break;
    }
    return 0;
}
