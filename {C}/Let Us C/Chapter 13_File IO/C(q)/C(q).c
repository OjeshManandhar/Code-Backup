#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include <extract.h>

int compare (const void *elem1, const void *elem2)
{
    char *a = *(char**)elem1;
    char *b = *(char**)elem2;
    /*
    data_type   variable    =   (pointer to array what we are comparing)  variable
    Eg:
    int         a           =   *(int *)elem
    struct      data        =   (struct *)elem
                structures use garda compare garne time my pointer use garne

    http://stackoverflow.com/questions/14993282/qsort-did-not-sort-the-array-of-string
    */

    return strcmpi(a,b);
}

int main()
{
    FILE *fp;
    int i,length=0,pos=0,start=0,count=0,flag=0;
    char c,buff[11],*source=NULL,*ch,**list=NULL;
    fp=fopen("file_C(q).txt","r");
    if (fp==NULL)
    {
        perror("Can't open file");
        exit(EXIT_FAILURE);
    }
    while (fgets(buff,10,fp)!=NULL)
    {
        length+=10;
        if (length==10)
        {
            source=(char *)malloc(length*sizeof(source));
            strcpy(source,buff);
        }
        else
        {
            source=(char *)realloc(source,length*sizeof(char));
            strcat(source,buff);
        }
    }
    while (1)
    {
        c=source[pos];
        if (c=='\0')
            break;
        else
        {
            if (c=='\n')
                pos++;     //eauta '\n' ra aaarko '\r' wa '\0' ko lagi tala add hunxa
            else if (c==' ')
            {
                flag=1;
                count++;
                length=pos-start+1;
                ch=(char *)malloc(length*sizeof(char));
                ch=mid(source,start+1,length-1);
                start=pos+1;
            }
            else if (c=='.' || c==',')
            {
                flag=1;
                count++;
                length=pos-start+1;
                ch=(char *)malloc(length*sizeof(char));
                ch=mid(source,start+1,length-1);
                pos++;
                start=pos+1;
            }
            pos++;
            if (flag==1)
            {
                flag=0;
                i=count-1;
                if (count==1)
                    list=(char **)malloc(count*sizeof(char *));
                else
                    list=(char **)realloc(list,count*sizeof(char *));
                list[i]=(char *)malloc(length*sizeof(char));
                strcpy(list[i],ch);
            }
        }
    }
    if (count==0)
        puts("No content found.");
    else
    {
        printf("Total Number of words in the list is %d.\n",count);
        puts("Alphabetical listing of words is:");
        qsort(list,count,sizeof(char *),compare);
        for (i=0;i<count;i++)
            puts(list[i]);
        puts("ZZZZZZZZZ");
    }
    free(source);
    free(ch);
    for (i=0;i<count;i++)
        free(list[i]);
    free(list);
    fclose(fp);
    return 0;
}
