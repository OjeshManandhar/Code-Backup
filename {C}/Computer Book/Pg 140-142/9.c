#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c,ch;
    float tsc,vat;
    printf("Enter total number telephone calls: ");
    scanf("%d",&c);
    if (c<=175)
        ch=200;
    else
        ch=200+(c-175);
    tsc=(15/100.0)*ch;
    vat=(13/100.0)*(ch+tsc);
    printf("\nTSC=Rs.%.2f.\nVAT=Rs.%.2f.\nTotal=%.2f.\n",tsc,vat,ch+tsc+vat);
    return 0;
}
