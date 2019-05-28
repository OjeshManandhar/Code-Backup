#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>

int main()
{
	int gd = DETECT, gm, errorcode;
	int mid_x, mid_y;
	int radius, color;

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

	mid_x = getmaxx()/2;
	mid_y = getmaxy()/2;

	color = 0;
	radius = 0;

	while (1)
	{
		setcolor(color++);
		circle(mid_x, mid_y, radius);

		radius += 10;
		
		if ((mid_x - radius) <= 0)
			break;

		if ((mid_y - radius) <= 0)
			break;
	}

	getch();
	closegraph();
	return 0;
}