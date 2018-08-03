#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int strtoint(const char);
int main()
{
    int i,x=0;
    char str[50];
    printf("Enter a integer/whole number [AS STRING]: ");
    scanf("%s",str);
    for (i=0;i<strlen(str);i++)
        x=x*10+strtoint(str[i]);
    printf("\nThe number you have entered is %d [AS INTEGER].\n",x);
    return 0;
}

int strtoint(const char s)
{
    if (s=='1')
        return 1;
    else if (s=='2')
        return 2;
    else if (s=='3')
        return 3;
    else if (s=='4')
        return 4;
    else if (s=='5')
        return 5;
    else if (s=='6')
        return 6;
    else if (s=='7')
        return 7;
    else if (s=='8')
        return 8;
    else if (s=='9')
        return 9;
    else if (s=='0')
        return 0;
}
