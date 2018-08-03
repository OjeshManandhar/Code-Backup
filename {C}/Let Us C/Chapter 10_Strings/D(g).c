#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <strtoint.h>

int main()
{
    char n[19],a[8],b[8];
    int i,j,c,ac=0,bc=0,at=0,bt=0,x,y;
    printf("Enter the credit-card number [INCLUDING SPACES]: ");
    gets(n);
    for (i=0;i<19;i+=5)
        for (j=i,c=1;j<=i+3;j++,c++)
            if (c%2!=0)
            {
                a[ac]=n[j];
                ac++;
            }
            else
            {
                b[bc]=n[j];
                bc++;
            }
    for (i=0;i<8;i++)
    {
        x=cint(a[i]);
        y=cint(b[i]);
        if (x>=5)
            at+=x*2-9;
        else
            at+=x*2;
        bt+=y;
    }
    if ((at+bt)%10==0)
        printf("\nThe credit-card number is correct.\n");
    else
        printf("\nThe credit-card not number is correct.\n");
    return 0;
}
