#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

void gotoxy(int row,int col)        //"row" ra "col" exchange gareko xa yo linema sajiloko lagi|
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position={col,row};
    SetConsoleCursorPosition(h,position);
}

void print_box()
{
    int i,j;
    for (i=1;i<=23;i++)
    {
        for (j=0;j<=79;j++)
        {
            gotoxy(i,j);
            if (i==1 || i==23)
                printf("%c",205);
            else if (j==0 || j==79)
                printf("%c",186);
        }
        printf("\n");
    }
    gotoxy(1,0);
    printf("%c",201);
    gotoxy(1,79);
    printf("%c",187);
    gotoxy(23,0);
    printf("%c",200);
    gotoxy(23,79);
    printf("%c",188);
}

int main()
{
    FILE *fp;
    int row=2,col=2,flag=1,page=0,print_flag;
    char c,name[26],*command;
    printf("Enter the name of the file [MAX 26 CHARACTERS]:\n");
    gets(name);
    fp=fopen(name,"r");
    if (fp==NULL)
    {
        perror("Can't open file");
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        if (flag==1)
        {
            page++;
            system("cls");
            print_box();
            gotoxy(0,0);
            printf("%-32s",name);
            gotoxy(0,40);
            printf("%34.2d|Page",page);
            row=2;
            flag=0;
        }
        c=fgetc(fp);
        if (c==EOF)
        {
            command="End of file. Press any key to exit...";
            gotoxy(24,0);
            printf("%79s",command);
            getch();
            break;
        }
        else if (c=='\n')
        {
            row++;
            col=2;
        }
        else if (c=='\t')
            col+=7;
        else if (c==' ')
            col+=2;
        else
            print_flag=1;
        if (col==78 && row<22)
        {
            row++;
            col=2;
        }
        if (col>78)
        {
            row++;
            col%=78;
        }
        if (row==22 && col==78)
        {
            getch();
            flag=1;
            col=2;
            print_flag=0;
        }
        if (row>22)
        {
            getch();
            flag=1;
        }
        if (print_flag==1)
        {
            gotoxy(row,col);
            putch(c);
            print_flag=0;
            col++;
        }
        if (row==22)
        {
            command="Press any key...";
            gotoxy(24,0);
            printf("%79s",command);
        }
    }
    fclose(fp);
    return 0;
}
