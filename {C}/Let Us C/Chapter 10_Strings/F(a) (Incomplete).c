#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <extract.h>

char *replace(char *,char *,char *,int *);

int main()
{
    char *str[]={
                    "We will teach you how to...",
                    "Move a mountain",
                    "Level a building",
                    "Erase the past",
                    "Make a million",
                    "...all through C!"
                },*str1,*str2,n[50];
    int i,flag=0;
    for (i=0;i<6;i++)
        puts(str[i]);
    printf("\nEnter the string to search: ");
    gets(n);
    str1=(char *)malloc(strlen(n)*sizeof(char));
    strcpy(str1,n);
    printf("Enter the string to replace(if found): ");
    gets(n);
    str2=(char *)malloc(strlen(n)*sizeof(char));
    strcpy(str2,n);
    for (i=0;i<6;i++)
    {
        str[i]=replace(str[i],str1,str2,&flag);
        if (flag==1)
        {
            printf("\n\nThe word that you have searched is found and replaced.\n\n");
            for (i=0;i<6;i++)
                puts(str[i]);
            exit(1);
        }
        else if (i==5 && flag==0)
            printf("\n\nThe word that you have searched is not found.\n");
    }
    return 0;
}

char *replace(char *str,char *str1,char *str2,int *flag)
{
    char n[50],*tempb,*tempe;
    int len,len1,i,j,c;
    len=strlen(str);
    len1=strlen(str1);
    for (i=0;i<(len+1-len1);i++)
    {
        for (j=i,c=0;c<len1;j++,c++)
            n[c]=str[j];
        n[c]=0;
        if (strcmp(n,str1)==0)
        {
            *flag=1;
            tempb=left(str,i);
            tempe=right(str,len-i-len1);
            strcat(tempb,str2);
            strcat(tempb,tempe);
            free(str);
            str=(char *)malloc(strlen(tempb)*sizeof(char));
            strcpy(str,tempb);
            break;
        }
    }
    return str;
}
