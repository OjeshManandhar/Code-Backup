#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define HLINE for(i=0;i<79;i++)\
                    printf("%c",196);
#define VLINE(X,Y)  {\
                        gotoxy(X,Y);\
                        printf("%c",179);\
                    }

void gotoxy(int,int);
int main()
{
    int i,y;
    system ("cls");
    gotoxy(1,12);

    HLINE

    for (y=1;y<25;y++)
        VLINE(39,y)
    return 0;
}

void gotoxy(int col,int row)
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position={col,row};
    SetConsoleCursorPosition(h,position);
}
