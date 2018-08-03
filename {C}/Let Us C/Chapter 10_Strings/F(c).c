#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char n[50],*s[]= {
                        "To err is human...",
                        "But to really mess things up...",
                        "One needs to know C!!"
                    };
    int i;
    for (i=0;i<3;i++)
        puts(s[i]);
    printf("\nReversing the strings.\n\n");
    for (i=0;i<3;i++)
    {
        strcpy(n,s[i]);
        puts(strrev(n));
    }
    return 0;
}
