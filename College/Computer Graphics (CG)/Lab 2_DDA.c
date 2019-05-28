#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>

void draw_line(const int, const int, const int, const int);

int main()
{
	int gd = DETECT, gm, errorcode;
	int i;

	clrscr();
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	errorcode = graphresult();
	if (errorcode != grOk)  /* an error occurred */
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(EXIT_FAILURE); /* terminate with an error code */
	}

	for (i = 100; i <= 200; i += 25)
	{
		draw_line(100, i, 200, i);
		draw_line(i, 100, i, 200);
	}

	draw_line(150, 100, 200, 150);
	draw_line(100, 100, 200, 200);
	draw_line(100, 150, 150, 200);

	draw_line(150, 100, 100, 150);
	draw_line(200, 100, 100, 200);
	draw_line(200, 150, 150, 200);

	getch();
	closegraph();
	return 0;
}

void draw_line(const int x1, const int y1, const int x2, const int y2)
{
	int dx, dy, step, i;
	float x, y, x_inc, y_inc;

	dx = x2 - x1;
	dy = y2 - y1;

	if (abs(dx) > abs(dy))
		step = abs(dx);
	else
		step = abs(dy);

	x_inc = (float)dx/(float)step;
	y_inc = (float)dy/(float)step;

	x = x1;
	y = y1;

	for (i = 0; i <= step; i++)
	{
		putpixel((int)x, (int)y, WHITE);
		delay(10);
		x += x_inc;
		y += y_inc;
	}
}