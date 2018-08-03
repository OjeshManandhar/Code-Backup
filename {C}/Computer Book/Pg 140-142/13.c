#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    char c;
    printf("Enter any 2 integers [SEPERATED BY A TAB]: ");
    scanf("%d%d",&a,&b);
    fflush(stdin);
    printf("Enter a operator(+, -, *, / or %): ");
    scanf("%c",&c);
    if (c=='+')
        printf("\n%d + %d = %d\n",a,b,a+b);
    else if (c=='-')
        printf("\n%d - %d = %d\n%d - %d = %d\n",a,b,a-b,b,a,b-a);
    else if (c=='*')
        printf("\n%d * %d = %d\n",a,b,a*b);
    else if (c=='/')
        printf("\n%d / %d = %.2f\n%d / %d = %.2f\n",a,b,a*1.0/b*1.0,b,a,b*1.0/a*1.0);
    else if (c=='%')
        printf("\n%d %c %d = %d\n%d %c %d = %d\n",a,'%',b,a%b,b,'%',a,b%a);
    return 0;
}
