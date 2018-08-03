#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include <extract.h>

int main()
{
    FILE *fp;
    int length=0,pos=0,start=0;
    char c,buff[11],*source=NULL,*ch;
    fp=fopen("INPUT.txt","r");
    if (fp==NULL)
    {
        perror("Can't open source");
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
    puts("The words of the content are reversed [IF GRAMMATICALLY CORRECT] as:\n");
    while (1)
    {
        c=source[pos];
        if (c=='\0')
            break;
        else if (c==' ' || c=='.' || c==',' || c=='\n')
        {
            length=pos-start+1;
            ch=(char *)malloc(length*sizeof(char));
            ch=mid(source,start+1,length-1);
            strrev(ch);
            printf("%s",ch);
            if (c==' ')
                printf(" ");
            else if (c=='.' || c==',')
            {
                printf("%c",c);
                pos++;
                printf("%c",source[pos]);
            }
            if (c=='\n')
                printf("\n");
            start=pos+1;
        }
        pos++;
    }
    free(source);
    free(ch);
    fclose(fp);
    return 0;
}
