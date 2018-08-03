#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <strtoint.h>

struct employee
{
    int code;
    char *name;
    char year[11];
}*data;

int arr[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int month(int y,int m,int d)
{
    if ((y%400==0 || (y%100!=0 && y%4==0)) && m==2)
        return (29-d);
    else
        return (arr[m]-d);
}

int y_end(int y,int m)
{
    int i,d=0;
    for (i=m;i<=12;i++)
        d+=month(y,i,0);
    return d;
}

int y_begin(int y,int m)
{
    int i,d=0;
    for (i=1;i<=m;i++)
        d+=month(y,i,0);
    return d;
}

int datesub(int y1, int m1, int d1, int y2, int m2, int d2)
{
    int d=0;
    if (y1==y2 && m1==m2)
        d=d2-d1;
    else if (y1==y2 && m1!=m2)
    {
        d+=month(y1,m1,d1);
        for (m1++;m1<m2;m1++)
            d+=month(y1,m1,0);
        d+=d2;
    }
    else
    {
        d+=month(y1,m1,d1);
        d+=y_end(y1,m1+1);
        for (y1++;y1<y2;y1++)
            d+=y_end(y1,1);
        d+=y_begin(y2,m2-1);
        d+=d2;
    }
    return d;
}

void change(char date[11],int *y,int *m,int *d)
{
    char temp[5];
    temp[0]=date[0];
    temp[1]=date[1];
    temp[2]=date[2];
    temp[3]=date[3];
    temp[4]=0;
    *y=sint(temp);
    temp[0]=date[5];
    temp[1]=date[6];
    temp[2]=0;
    *m=sint(temp);
    temp[0]=date[8];
    temp[1]=date[9];
    temp[2]=0;
    *d=sint(temp);
}

int main()
{
    int n,i,l,y1,m1,d1,y2,m2,d2,f;
    char ch[25],date[11];
    f=y1=y2=m1=m2=d1=d2=0;
    printf("Enter the no. of data to be entered: ");
    scanf("%d",&n);
    data=(struct employee*)malloc(n*sizeof(struct employee));
    for (i=0;i<n;i++)
    {
        printf("\nEnter the EMPLOYEE CODE of employee no.%d: ",i+1);
        scanf("%d",&data[i].code);
        fflush(stdin);
        printf("Enter the NAME of employee no.%d: ",i+1);
        gets(ch);
        l=strlen(ch);
        data[i].name=(char *)malloc(l*sizeof(char));
        strcpy(data[i].name,ch);
        printf("Enter the DATE OF JOINING of employee no.%d [FORMAT: YYYY/MM/DD]: ",i+1);
        gets(data[i].year);
    }
    printf("\nAll data(s) have been entered. Press any key.");
    getch();
    system("cls");
    printf("Displaying Information on employee whose tenure is greater than equal to 3 year.\n");
    printf("Enter current date [FORMAT: YYYY/MM/DD]: ");
    gets(date);
    change(date,&y2,&m2,&d2);
    for (i=0;i<n;i++)
    {
        change(data[i].year,&y1,&m1,&d1);
        if (f==0 && datesub(y1,m1,d1,y2,m2,d2)>=(365*3))
        {
            f=1;
            printf("\nThe data(s) of employee whose tenure is greater than equal to 3 year is/are:\n\n");
            printf("Code\tName\tDate\n");
            printf("%d\t%s\t%s\n",data[i].code,data[i].name,data[i].year);
        }
        else if (f==1 && datesub(y1,m1,d1,y2,m2,d2)>=(365*3))
            printf("%d\t%s\t%s\n",data[i].code,data[i].name,data[i].year);
    }
    if (f==0)
        printf("\n\tNO DATA FOUND.\n");
	free(data);
    return 0;
}
