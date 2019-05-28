#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void draw_circle(int, int ,int);

int main()
{
	int gd = DETECT, gm;
	int x, y, r;

	clrscr();
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	x = getmaxx()/2;
	y = getmaxy()/2;
	r = 0;

	while (1)
	{
		r += 10;
		if (x - r <= 0)
			break;
		if (y - r <= 0)
			break;

		draw_circle(x, y, r);
	}

	getch();
	closegraph();
	return 0;
}

void draw_circle(int x, int y, int r)
{
	int xk, yk, pk;

	xk = 0;
	yk = r;

	pk = 1- r;

	while (xk < yk)
	{
		putpixel(xk + x, yk + y, WHITE);
		putpixel(yk + x, xk + y, RED);
		putpixel(yk + x, -xk + y, RED);
		putpixel(xk + x, -yk + y, BLUE);
		putpixel(-xk + x, -yk + y, BLUE);
		putpixel(-yk + x, -xk + y, GREEN);
		putpixel(-yk + x, xk + y, GREEN);
		putpixel(-xk + x, yk + y, WHITE);
		delay(10);

		if (pk < 0)
		{
			xk = xk + 1;
            yk = yk;
            pk = pk + 2*xk + 1;
        }
        else
        {
            xk = xk + 1;
            yk = yk - 1;
            pk = pk + 2*xk - 2*yk + 1;
        }
    }
}