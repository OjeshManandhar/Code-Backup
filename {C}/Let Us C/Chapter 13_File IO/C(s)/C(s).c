#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main()
{
    FILE *fp;
    int row=1,col=1,flag=0;
    char c;
    fp=fopen("cheats.txt","r");
    if (fp==NULL)
    {
        perror("Can't open file");
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        if (flag==1)
        {
            flag=0;
            printf("\n%s","Change the paper and press any key to continue...");
            getch();
            system("cls");
            row=col=1;
        }
        c=fgetc(fp);
        if (c==EOF)
        {
            printf("\n\n%s","End of file. Press any key to exit...");
            getch();
            break;
        }
        else if (c=='\t')
            col+=7;
        else if (c=='\n')
        {
            row++;
            col=0;
        }
        else
            col++;
        printf("%c",c);
        if (col>80)
        {
            row++;
            printf("\n");
            col%=80;
        }
        if (row==50 && col==80)
            flag=1;
        if (row>50)
            flag=1;
        //getch();
    }
    return 0;
}
