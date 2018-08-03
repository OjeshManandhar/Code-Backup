#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main()
{
    FILE *fp;
    int pos=0,start=0,count=0,count_4=0,flag=0;
    char c;
    fp=fopen("TRIAL.txt","r");
    if (fp==NULL)
    {
        perror("Can't open file");
        exit(EXIT_SUCCESS);
    }
    while (1)
    {
        fseek(fp,pos,SEEK_SET);
        c=fgetc(fp);
        if (c==EOF)
            break;
        if (flag==1)
        {
            flag=0;
            if (c==' ')
                pos++;
            else if (c=='\n')
                pos+=2;
            start=pos;
        }
        else
        {
            if (c=='\n')
                pos++;     //eauta '\n' ra aaarko '\r' wa '\0' ko lagi tala add hunxa
            else if (c==' ' && (pos-start==4))
            {
                count++;
                count_4++;
                start=pos+1;
            }
            else if ((c=='.' || c==',') && (pos-start==4))
            {
                count++;
                count_4++;
                flag=1;
            }
            else if (c==' ')
            {
                count++;
                start=pos+1;
            }
            else if (c=='.' || c==',')
            {
                count++;
                flag=1;
            }
            pos++;
        }
    }
    puts("If the content of the file is grammatically correct then,");
    printf("The total number of words is: %d.\n",count);
    printf("The total number of four letter words is: %d.\n",count_4);
	fclose(fp);
    return 0;
}
