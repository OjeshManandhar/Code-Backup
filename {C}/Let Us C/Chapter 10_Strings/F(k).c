#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strtoint.h>
#include <extract.h>

char *number(char *x,int);

int main()
{
    int len,i=0,t,flag=0;
    char n[14],*x,*text,ans[100];
    printf("Enter a number [WITHOUT COMMA(S)] [LIMIT < 100,00,00,00,00,000]: ");
    gets(n);
    if (sint(n)==0)
    {
        printf("The number you entered in words is: Zero.\n");
        exit(1);
    }
    len=strlen(n);
    if (len<=2)
        t=0;
    else if (len==3)
        t=1;
    else if (len<=5)
        t=2;
    else if (len<=7)
        t=3;
    else if (len<=9)
        t=4;
    else if (len<=11)
        t=5;
    else if (len<=13)
        t=6;
    if (len==1 || len==4 || len==6 || len==8 || len==10 || len==12)
    {
        strrev(n);
        strcat(n,"0");
        len++;
        strrev(n);
    }
    if (len>3)
        for (i=0;i<len-3;i+=2,t--)
        {
            x=mid(n,i+1,2);
            text=number(x,t);
            if (i==0)
                strcpy(ans,text);
            else
                strcat(ans,text);
        }
    if (len>=3)
    {
        flag=1;
        x=mid(n,i+1,1);
        text=number(x,1);
        if (i==0)
            strcpy(ans,text);
        else
            strcat(ans,text);
        i++;
    }
    x=mid(n,i+1,2);
    text=number(x,0);
    if (flag==1)
        strcat(ans,text);
    else
        strcpy(ans,text);
    printf("\nThe number you entered in words is: ");
    puts(ans);
    return 0;
}

char *number(char *x,int t)
{
    int n,t1,t2;
    char *a[]={"","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine ","Ten ","Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen "};
    char *b[]={"Twenty ","Thirty ","Forty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety "};
    char *p[]={"","Hundred ","Thousand ","Lakha ","Crore ","Arab ","Kharab "};
    char ans[100];
    n=sint(x);
    if (n<20)
        strcpy(ans,a[n]);
    else if (n>=20)
    {
        t1=n/10-2;
        t2=n%10;
        strcpy(ans,b[t1]);
        strcat(ans,a[t2]);
    }
    if (n!=0)
        strcat(ans,p[t]);
    return ans;
}
