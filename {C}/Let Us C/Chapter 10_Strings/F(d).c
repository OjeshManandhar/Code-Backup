#include <stdio.h>
#include <stdlib.h>

void print(int,int,int);

int main()
{
    int y,m,i,f=1,j,c;
    printf("Enter the year [LIMIT: MORE THAN 1898]: ");
    scanf("%d",&y);
    printf("Enter the month [IN NUMBERS]: ");
    scanf("%d",&m);
    for (i=1899;i<=y;i++)
    {
        if (i==y)
            for (j=1,c=f;j<=m;j++)
            {
                if (j==m)
                    print(y,m,c);
                else if (j==1 || j==3 || j==5 || j==7 || j==8 || j==10 || j==12)
                    c+=31;
                else if (j==4 || j==6 || j==9 || j==11)
                    c+=30;
                else if (j==2)
                    if (y%400==0 || y%100!=0 && y%4==0)
                        c+=29;
                    else
                        c+=28;
                if (j==m-1)
                    c=c%7;
                if (c==0)
                    c=7;
            }
        else if (i%400==0 || i%100!=0 && i%4==0)
            f+=2;
        else
            f++;
        if (f>7)
            f%=7;
        if (f==0)
            f=7;
    }
    printf("\n");
    return 0;
}

void print(int y,int m,int f)
{
    int d=1,i,n;
    if (m==1)
        printf("\n\t\t     Jan %d\n",y);
    else if (m==2)
        printf("\n\t\t     Feb %d\n",y);
    else if (m==3)
        printf("\n\t\t     Mar %d\n",y);
    else if (m==4)
        printf("\n\t\t     Apr %d\n",y);
    else if (m==5)
        printf("\n\t\t     May %d\n",y);
    else if (m==6)
        printf("\n\t\t     Jun %d\n",y);
    else if (m==7)
        printf("\n\t\t     Jul %d\n",y);
    else if (m==8)
        printf("\n\t\t     Aug %d\n",y);
    else if (m==9)
        printf("\n\t\t    Sept %d\n",y);
    else if (m==10)
        printf("\n\t\t     Oct %d\n",y);
    else if (m==11)
        printf("\n\t\t     Nov %d\n",y);
    else if (m==12)
        printf("\n\t\t     Dec %d\n",y);
    printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
    if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
        n=31;
    else if (m==4 || m==6 || m==9 || m==11)
        n=30;
    else if (m==2)
        if (y%400==0 || y%100!=0 && y%4==0)
            n=29;
        else
            n=28;
    do
    {
        for (i=1;i<(n+f);i++)
        {
            if (i>=f)
            {
                printf("%d\t",d);
                d++;
            }
            else
                printf("\t");
            if (i%7==0)
                printf("\n");
        }
    }while (d<=n);
}
