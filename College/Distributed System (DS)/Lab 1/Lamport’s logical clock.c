#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
	int i, j, k;
	int x = 0;
	char a[10][10];
	int n, num[10], b[10][10];

	system("cls");

	printf("Enter the no. of physical clocks: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("\nNo. of nodes for physical clock %d: ", i+1);
		scanf("%d", &num[i]);
		x = 0;
		for (j = 0; j < num[i]; j++)
		{
			printf("Enter the name of process: ");
			fflush(stdin);
			scanf("%c", &a[i][j]);
			b[i][j] = x + rand() % 10;
			x = b[i][j] + 1;
		}
	}

	printf("\nPress a key for watching timestamp of physical clocks");
	getch();
	system("cls");

	for(i = 0; i < n; i++)
	{
		printf("Physical Clock %d: \n", i+1);
		for (j = 0; j < num[i]; j++)
			printf("Process: %c has P.T.: %d \n", a[i][j], b[i][j]);
        printf("\n\n");
	}

	printf("Press a key for watching timestamp of logical clocks");
	getch();
	system("cls");

	x = 0;
	for(i = 0; i < 10; i++)
		for(j = 0; j < n; j++)
			for(k = 0; k < num[j]; k++)
				if(b[j][k] == i)
				{
					x = rand()%10 + x;
					printf("Logical Clock Timestamp for process %c: %d\n", a[j][k], x);
				}

	return 0;
}

/*
Output;
Enter the no. of physical clocks: 2
No. of nodes for physical clock 1: 2
Enter the name of process: a
Enter the name of process: b
No. of nodes for physical clock 2: 2
Enter the name of process: c
Enter the name of process: d
Press a key for watching timestamp of physical clocks
Physical Clock 1
Process a has P.T.: 1
Process b has P.T.: 9
Physical Clock 2
Process c has P.T.: 4
Process d has P.T.: 5
Press a key for watching timestamp of logical clocks
Logical Clock Timestamp for process a: 9
Logical Clock Timestamp for process b: 13
Logical Clock Timestamp for process c: 21
Logical Clock Timestamp for process d: 29
*/
