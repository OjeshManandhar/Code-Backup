#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lower.h>

int compare(const char, const char);

int main()
{
    int len,i,count=0;
    char n[100];
    printf("Enter a sentence: ");
    gets(n);
    len=strlen(n);
    for (i=0;i<len-1;i++)
        if(compare(n[i],n[i+1])==1)
            count++;
    printf("\nTotal no. of occurrences of any two vowels in succession is: %d\n",count);
    return 0;
}

int compare(const char a,const char b)
{
    int f1=0,f2=0;
    char x,y;
    x=clwr(a);
    y=clwr(b);
    if (x=='a' || x=='e' || x=='i' || x=='o' || x=='u')
        f1=1;
    if (f1==0)
        return 0;
    else if (y=='a' || y=='e' || y=='i' || y=='o' || y=='u')
        f2=1;
    if (f2==1)
        return 1;
    else
        return 0;
}
