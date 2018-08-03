#include <stdio.h>
#include <stdlib.h>
#define UPPER(ch){\
                    if (ch>=65 && ch<=90)\
                        printf("\nThe character is UPPER CASE.\n");\
                    else\
                        printf("\nThe character is NOT a UPPER CASE.\n");\
                  }
int main()
{
    char a;
    printf("Enter a alphabet: ");
    scanf("%c",&a);
    UPPER (a);
    return 0;
}
