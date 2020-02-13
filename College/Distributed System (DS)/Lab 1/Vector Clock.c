#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

long *p1(int i, long *comp);
long *p2(int i, long *comp);
long *p3(int i, long *comp);
long *pP(int p, int i, long *comp);

int main()
{
	long start[] = {0, 0, 0}, *vector = NULL;

	while(!kbhit())
	{
		// p1(1, start);
		pP(1, 1, start);
	}

	printf("Process Vector\n");
	// vector = p1(0, start);
	vector = pP(1, 0, start);
	printf("p1[%ld %ld %ld]\n", vector[0], vector[1], vector[2]);
	// vector = p2(0, start);
	vector = pP(2, 0, start);
	printf("p2[%ld %ld %ld]\n" , vector[0], vector[1], vector[2]);
	// vector = p3(0, start);
	vector = pP(3, 0, start);
	printf("p3[%ld %ld %ld]\n" , vector[0], vector[1], vector[2]);

	system("pause");

	return 0;
}

long *p1(int i, long *comp)
{
	static long a[] = {0, 0, 0};
	int next;

	if (i == 1)
	{
		a[0]++;
		if (*(comp + 1) > a[1])
			a[1] = *(comp + 1);
		if (*(comp + 2) > a[2])
			a[2] = *(comp + 2);

		next = rand()%2;

		if (next == 0)
			p2(1, a);
		else if(next == 1)
			p3(1, a);
		return(a);
	}
	else
		return(a);
}

long *p2(int i,long *comp)
{
	static long b[] = {0, 0, 0};
	int next;

	if (i == 1)
	{
		b[i]++;
		if (*comp > b[0])
			b[0] = *(comp);
		if (*(comp + 2) > b[2])
			b[2] = *(comp + 2);

		next = rand()%2;

		if (next == 0)
			p1(1, b);
		else if(next == 1)
			p3(1, b);
		return(b);
	}
	else
		return(b);
}

long *p3(int i, long *comp)
{
	static long c[] = {0, 0, 0};
	int next;

	if(i==1)
	{
		c[2]++;
		if (*comp > c[0])
			c[0] = *(comp);
		if (*(comp + 1) > c[1])
			c[1] = *(comp + 1);

		next = rand()%2;

		if (next == 0)
			p1(1, c);
		return c;
	}
	else
		return c;
}

long *pP(int p, int i, long *comp)
{
    static long vec[3][3] = {0};
    int j, next, pos = p - 1;

    if (i == 1)
    {
        vec[pos][pos]++;

        for (j = 0; j < 3; j++)
            if (j != pos)
                if (comp[j] > vec[pos][j])
                    vec[pos][j] = comp[j];

		next = rand()%2;

		if (next == 0)
        {
            if (p == 1)
                pP(2, 1, vec[pos]);
            else if (p == 2 || p == 3)
                pP(1, 1, vec[pos]);
        }
        else if (next == 1)
        {
            if (p == 1 || p == 2)
                pP(3, 1, vec[pos]);
        }
    }

    return vec[pos];
}
