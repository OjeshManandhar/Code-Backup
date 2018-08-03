#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int getkey();
void print(int,int,int);

int main()
{
    int y,m,i,f=1,j,c,ch;
    do
    {
        system("cls");
        printf("Enter the year [LIMIT: MORE THAN 1898]: ");
        scanf("%d",&y);
    }while (y<1899);
    do
    {
        system("cls");
        printf("Enter the year [LIMIT: MORE THAN 1898]: %d\n",y);
        printf("Enter the month [IN NUMBERS]: ");
        scanf("%d",&m);
    }while (m<1 || m>12);
    do
    {
        system("cls");
        for (i=1899,f=1;i<=y;i++)
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
                        if (y%400==0 || (y%100!=0 && y%4==0))
                            c+=29;
                        else
                            c+=28;
                    if (j==m-1)
                        c=c%7;
                    if (c==0)
                        c=7;
                }
            else if (i%400==0 || (i%100!=0 && i%4==0))
                f+=2;
            else
                f++;
            if (f>7)
                f%=7;
            if (f==0)
                f=7;
        }
        printf("\n\nEnter a key:\n");
        printf("1. UP Arrow key\t\t: Next year, Same month.\n");
        printf("2. DOWN Arrow key\t: Previous year, Same month.\n");
        printf("3. LEFT Arrow key\t: Same year, Next month.\n");
        printf("4. RIGHT Arrow key\t: Same year, Previous month.\n");
        printf("5. ESC key\t\t: Terminate the program.\n");
        ch=getkey();
        switch (ch)
        {
        case 72: //Up
            y++;
            break;
        case 80: //DOWN
            if (y>1899)
                y--;
            else
            {
                y==1899;
                m=1;
            }
            break;
        case 75: //LEFT
            if (y>1899)
                if (m>1)
                    m--;
                else
                {
                    y--;
                    m=12;
                }
            else
                if (m>1)
                    m--;
                else
                {
                    y==1899;
                    m=1;
                }
            break;
        case 77: //RIGHT
            if (m==12)
            {
                y++;
                m=1;
            }
            else
                m++;
            break;
        case 27: //ESC
            system("cls");
            printf("Program Terminated. Press any key to exit.\n");
            getch();
            break;
        }
    }while (ch!=27);
    return 0;
}

int getkey()
{
    int ch;
    ch=getch();
    if (ch==224)
    {
        ch=getch();
        return ch;
    }
    return ch;
}

void print(int y,int m,int f)
{
    int d=1,i,n;
    if (m==1)
        printf("\t\t     Jan %d\n\n",y);
    else if (m==2)
        printf("\t\t     Feb %d\n\n",y);
    else if (m==3)
        printf("\t\t     Mar %d\n\n",y);
    else if (m==4)
        printf("\t\t     Apr %d\n\n",y);
    else if (m==5)
        printf("\t\t     May %d\n\n",y);
    else if (m==6)
        printf("\t\t     Jun %d\n\n",y);
    else if (m==7)
        printf("\t\t     Jul %d\n\n",y);
    else if (m==8)
        printf("\t\t     Aug %d\n\n",y);
    else if (m==9)
        printf("\t\t    Sept %d\n\n",y);
    else if (m==10)
        printf("\t\t     Oct %d\n\n",y);
    else if (m==11)
        printf("\t\t     Nov %d\n\n",y);
    else if (m==12)
        printf("\t\t     Dec %d\n\n",y);
    printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
    if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
        n=31;
    else if (m==4 || m==6 || m==9 || m==11)
        n=30;
    else if (m==2)
        if (y%400==0 || (y%100!=0 && y%4==0))
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
