#include <stdio.h>
#include <stdlib.h>

void roman(int);
int main()
{
    int y;
    printf("Enter a year: ");
    scanf("%d",&y);
    roman(y);
    return 0;
}

void roman(int y)
{
    char p1,p5,p9;
    int q,d=1000,r,i;
    printf("\nIts Roman equivalent is: ");
    for (;d>=1;d/=10)
    {
        q=y/d;
        r=y%d;
        y=r;
        switch (d)
        {
        case 100:
            p1='C';
            p5='D';
            p9='M';
            break;
        case 10:
            p1='X';
            p5='L';
            p9='C';
            break;
        case 1:
            p1='I';
            p5='V';
            p9='X';
            break;
        }
        if (d==1000)
            for (i=1;i<=q;i++)
                printf("M");
        else if (q<=3)
            for (i=1;i<=q;i++)
                printf("%c",p1);
        else if (q==4)
            printf("%c%c",p1,p5);
        else if (q==5)
            printf("%c",p5);
        else if (q>5 && q<=8)
        {
            printf("%c",p5);
            for (i=1;i<=q-5;i++)
                printf("%c",p1);
        }
        else if (q==9)
            printf("%c%c",p1,p9);
    }
}
