#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include <extract.h>

void change(char *source,const char *s, const char *t)
{
    int i,length,ls,lt,size=1,flag=0;
    char *temp=NULL,*ch=NULL,c;
    length=strlen(source);
    ls=strlen(s);
    lt=strlen(t);
    ch=(char *)malloc((ls+1)*sizeof(char));
    for (i=0;i<length;)
    {
        if (flag==1)
        {
            flag=0;
            ch=mid(source,i+1,ls-1);
            if (strcmpi(ch,mid(s,2,ls-1))==0)
            {
                i+=(ls-1);
                size+=lt-1;
                temp=(char *)realloc(temp,size*sizeof(char));
                strcat(temp,mid(t,2,lt-1));
            }
            else
            {
                i++;
                size++;
                temp=(char *)realloc(temp,size*sizeof(char));
                strcat(temp,mid(ch,1,1));
            }
        }
        else if (i==0)
        {
            ch=mid(source,i+1,ls-1);
            if (strcmpi(ch,mid(s,2,ls-1))==0)
            {
                i+=(ls-1);
                size+=lt-1;
                temp=(char *)malloc(size*sizeof(char));
                strcpy(temp,mid(t,2,lt-1));
            }
            else
            {
                i++;
                size++;
                temp=(char *)malloc(size*sizeof(char));
                strcpy(temp,mid(ch,1,1));
            }
        }
        else
        {
            ch=mid(source,i+1,ls);
            if (strcmpi(ch,s)==0)
            {
                i+=ls;
                size+=lt;
                temp=(char *)realloc(temp,size*sizeof(char));
                strcat(temp,t);
            }
            else
            {
                i++;
                size++;
                temp=(char *)realloc(temp,size*sizeof(char));
                strcat(temp,mid(ch,1,1));
            }
        }
        c=ch[0];
        if (c=='\n')
            flag=1;
    }
    length=strlen(temp)+1;
    source=(char *)realloc(source,length*sizeof(char));
    strcpy(source,temp);
    free(temp);
}

int main()
{
    FILE *fs,*ft;
    int total=0,length;
    char buff[11],*ch;
    fs=fopen("file_C(n)_s.txt","r");
    if (fs==NULL)
    {
        perror("Can't open source");
        exit(EXIT_FAILURE);
    }
    ft=fopen("file_C(n)_t.txt","w");
    if (ft==NULL)
    {
        perror("Can't open target");
        exit(EXIT_FAILURE);
    }
    while (fgets(buff,10,fs)!=NULL)
    {
        length=strlen(buff)+1;
        total+=length;
        if (total-length==0)
        {
            ch=(char *)malloc(total*sizeof(char));
            strcpy(ch,buff);
        }
        else
        {
            ch=(char *)realloc(ch,total*sizeof(char));
            strcat(ch,buff);
        }
    }
    puts("The data in the source file is:\n");
    puts(ch);
    change(ch," a ","   ");
    change(ch," the ","   ");
    change(ch," an ","   ");
    puts("\n\nAll the \"a\", \"the\" and \"an\" are replaced with a space as:");
    puts("NOTE: Only if the content is grammatically correct.\n");
    puts(ch);
    fputs(ch,ft);
	free(ch);
    fclose(fs);
    fclose(ft);
    return 0;
}
