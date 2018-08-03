#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include <extract.h>

int main(int argc, char *argv[])
{
    FILE *fp,*ft;
    int length=0,pos=0,start=0;
    char c,buff[11],*source=NULL,*ch;
    if (argv!=4)
    {
        puts("Not enough arguments.");
        exit(EXIT_FAILURE);
    }
    fp=fopen(argv[3],"r");
    if (fp==NULL)
    {
        perror("Can't open file");
        exit(EXIT_FAILURE);
    }
    ft=fopen("temp.txt","w");

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
        else if (c==' ' || c=='.' || c==',' || c=='\n')
        {
            length=pos-start+1;
            ch=(char *)malloc(length*sizeof(char));
            ch=mid(source,start+1,length-1);
            if (strcmp(ch,argv[1])==0)
                fputs(argv[2],ft);
            else
                fputs(ch,ft);
            if (c==' ')
                fputc(' ',ft);
            else if (c=='.' || c==',')
            {
                fputc(c,ft);
                pos++;
                fputc(source[pos],ft);
            }
            if (c=='\n')
                printf("\n");
            start=pos+1;
        }
        pos++;
    }
    fclose(fp);
    fclose(ft);
    remove(argv[3]);
    rename("temp.txt",argv[3]);
    return 0;
}
