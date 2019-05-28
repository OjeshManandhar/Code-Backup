#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

#define PI 3.141592653589793

void init()
{
	int gd = DETECT, gm;

	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
}

void close()
{
    getch();
    closegraph();
}

void draw(int box[4][2])
{
    int i, j;

    for (i = 0; i < 4; i++)
    {
        j = (i + 1)%4;

        line(box[i][0], box[i][1], box[j][0], box[j][1]);
    }
}

void translate(int box[4][2])
{
    int tx, ty, i;
    int t_box[4][2];

    clrscr();
    printf("Enter tx and ty: ");
    scanf("%d%d", &tx, &ty);

    for (i = 0; i < 4; i++)
    {
        t_box[i][0] = box[i][0] + tx;
        t_box[i][1] = box[i][1] + ty;
    }

    init();

    setcolor(WHITE);
    draw(box);

    setcolor(RED);
    draw(t_box);

    close();
}

void scale(int box[4][2])
{
    int sx, sy, i;
    int s_box[4][2];

    clrscr();
    printf("Enter sx and sy: ");
    scanf("%d%d", &sx, &sy);

    for (i = 0; i < 4; i++)
    {
        s_box[i][0] = box[i][0] - 150;
        s_box[i][1] = box[i][1] - 150;
    }

    for (i = 0; i < 4; i++)
    {
        s_box[i][0] = s_box[i][0]*sx;
        s_box[i][1] = s_box[i][1]*sy;
    }

    for (i = 0; i < 4; i++)
    {
        s_box[i][0] = s_box[i][0] + 150;
        s_box[i][1] = s_box[i][1] + 150;
    }

    init();

    setcolor(WHITE);
    draw(box);

    setcolor(RED);
    draw(s_box);

    close();
}

void rotate(int box[4][2])
{
    float ang, temp_x, temp_y;
    int i, r_box[4][2];

    clrscr();
    printf("Enter angle to rotate: ");
    scanf("%f", &ang);

    for (i = 0; i < 4; i++)
    {
        r_box[i][0] = box[i][0] - 150;
        r_box[i][1] = box[i][1] - 150;
    }

    for (i = 0; i < 4; i++)
    {
        temp_x = r_box[i][0];
        temp_y = r_box[i][1];

        r_box[i][0] = temp_x*cos(ang) - temp_y*sin(ang);
        r_box[i][1] = temp_x*sin(ang) + temp_y*cos(ang);
    }

    for (i = 0; i < 4; i++)
    {
        r_box[i][0] = r_box[i][0] + 150;
        r_box[i][1] = r_box[i][1] + 150;
    }

    init();

    setcolor(WHITE);
    draw(box);

    setcolor(RED);
    draw(r_box);

    close();
}

int main()
{
    int box[4][2] = {
                        {100, 100},
                        {200, 100},
                        {200, 200},
                        {100, 200}
    };

    init();

    setcolor(WHITE);
    draw(box);
    
    close();

    translate(box);

    scale(box);

    rotate(box);

    return 0;
}