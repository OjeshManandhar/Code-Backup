#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>

void draw_ellipse(float, float, float, float);

int main()
{
	int gm = DETECT, gd, errorcode;
	int mid_x, mid_y;
	float rx, ry;
	int flag;

	clrscr();
	initgraph(&gm, &gd, "C:\\TURBOC3\\BGI");
	errorcode = graphresult();
	if (errorcode != grOk)  /* an error occurred */
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		fflush(stdin);
		getch();
		exit(EXIT_FAILURE); /* terminate with an error code */
	}

	mid_x = getmaxx()/2;
	mid_y = getmaxy()/2;

	rx = ry = 0;

	flag = 0;

	while (flag == 0)
	{
		draw_ellipse(mid_x, mid_y, rx, ry);

		rx += 10;
		ry += 10;

		if ((mid_x - rx) <= 0)
		{
			flag = 1;
			rx -= 10;

			while (1)
			{
				draw_ellipse(mid_x, mid_y, rx, ry);

				ry += 10;

				if ((mid_y - ry) <= 0)
					break;
			}
		}

		if ((mid_y - ry) <= 0)
		{
			flag = 1;
			ry -= 10;

			while (1)
			{
				draw_ellipse(mid_x, mid_y, rx, ry);

				rx += 10;

				if ((mid_x - rx) <= 0)
					break;
			}
		}
	}

	getch();
	closegraph();
	return 0;
}

void draw_ellipse(float xc, float yc, float rx, float ry)
{
	float x, y, p;

	x = 0;
	y = ry;
	p = (ry*ry) - (rx*rx*ry) + ((rx*rx)/4);

	while ((2*x*ry*ry) < (2*y*rx*rx))
	{
		putpixel(x + xc, y + yc, WHITE);
		putpixel(-x + xc, y + yc, RED);
		putpixel(-x + xc, -y + yc, BLUE);
		putpixel(x + xc, -y + yc, GREEN);
		delay(5);

		if (p < 0)
		{
			x = x + 1;
			p = p + (2*ry*ry*x) + (ry*ry);
		}
		else
		{
			x = x + 1;
			y = y - 1;
			p = p + (2*ry*ry*x+ry*ry) - (2*rx*rx*y);
		}
	}
	p = (x + 0.5)*(x + 0.5)*ry*ry + (y - 1)*(y - 1)*rx*rx - rx*rx*ry*ry;

	while (y >= 0)
	{
		putpixel(x + xc, y + yc, WHITE);
		putpixel(-x + xc, y + yc, RED);
		putpixel(-x + xc, -y + yc, BLUE);
		putpixel(x + xc, -y + yc, GREEN);
		delay(5);

		if (p > 0)
		{
			y = y - 1;
			p = p - (2*rx*rx*y) + (rx*rx);
		}
		else
		{
			y = y - 1;
			x = x + 1;
			p = p + (2*ry*ry*x) - (2*rx*rx*y) - (rx*rx);
		}
	}
}