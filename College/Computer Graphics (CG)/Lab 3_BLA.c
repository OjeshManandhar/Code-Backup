#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
#include <graphics.h>

void draw_line(int, int, int, int);

int main()
{
    int gd = DETECT, gm, errorcode;
    int x1, y1, x2, y2;

    clrscr();
    printf("Enter starting coordinate [SEPERATED BY A TAB]: ");
    scanf("%d%d", &x1, &x2);
    printf("Enter ending coordinates [SEPERATED BY A TAB]: ");
    scanf("%d%d", &x2, &y2);

    clrscr();
    errorcode = graphresult();
    if (errorcode != grOK)
    {
        printf("Graphics error: %s\n", grapherrormsg(errorcode));
        printf("Prerss any key to halt: ");
        fflush(stdin);
        getch();
        exit(EXIT_FAILURE);
    }

    draw_line(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

void draw_line(int x1, int y1, int x2, int y2)
{
    int del_x, del_y, dx, dy, pk, i;

    del_x = abs(x2 - x1);
    del_y = abs(y2 - y1);

    if (x2 > x1)
        dx = 1;
    else
        dx = -1;

    if (y2 > y1)
        dy = 1;
    else
        dy = -1;

    putpixel(x1, y1, WHITE);

    if (del_x > del_y)
    {
        pk = 2*del_y - del_x;

        for (i = 0; i <= del_x; i++)
        {
            if (pk < 0)
            {
                x1 = x1 + dx;
                y1 = y1;
                pk = pk + 2*del_y;
            }
            else
            {
                x1 = x1 + dx;
                y1 = y1 + dy;
                pk = pk + 2*del_y - 2*del_x;
            }

            putpixel(x1, y1, WHITE);
        }
    }
    else
    {
        pk = 2*del_x - del_y;

        for (i = 0; i <= del_y; i++)
        {
            if (pk < 0)
            {
                x1 = x1;
                y1 = y1 + dy;
                pk = pk + 2*del_x;
            }
            else
            {
                x1 = x1 + dx;
                y1 = y1 + dy;
                pk = pk + 2*del_x - 2*del_y;
            }

            putpixel(x1, y1, WHITE);
        }
    }
}