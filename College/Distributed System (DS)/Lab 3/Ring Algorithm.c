#include <stdio.h>
#include <conio.h>
#include <process.h>

struct proc
{
	int live;
	int identifier;
} process[10];

int n, cordinator = 1;

/* DISPLAY PROCESSES */
void display()
{
	int i;
	printf("\n PROCESSES ARE\n\n");

	printf("Processes ");
	for (i = 1; i <= n; i++)
		printf("P%d\t", i);

	printf("\nlive ");
	for (i = 1; i <= n; i++)
		printf("%d\t", process[i].live);

	printf("\nidentifier ");
	for (i = 1; i <= n; i++)
		printf("%d\t", process[i].identifier);
}

/* RING ALGORITHM */
void ring()
{
	int ch, c, id, i=0, init, max = -99, last;

	for (i = 1; i <= n; i++)
		if (process[cordinator].identifier>process[i].identifier && process[i].live == 1)
			cordinator = i;

	printf("\n NEW CO-ORDINATOR IS=P%d\n\n", cordinator);

	while(ch!=4)
	{
		printf("\n\n\n *** RING ALGORITHM ***");
		printf("\n1.Crash a Process\n2.Activate Process\n3.Display\n4.Exit");
		printf("\nENTER UR CHOICE");
		scanf("%d", &ch);

		switch(ch)
		{
		case 1:
			printf("\n Enter the process id to crash");
			scanf("%d", &id);
			if (process[id].live == 0)
				printf("\n Already crashed process");
			else
			{
				process[id].live = 0;
				printf("\n process P%d is crashed", id);
				if (id == cordinator)
					while(1)
					{
						printf("\n Enter process id who intiates election");
						scanf("%d", &init);
						if(process[init].live == 0)
							printf("\n the selected process is crashed");
						else
						{
							last = init;
							printf("\nElection MSG sent from =%d", last);
							for (i = init + 1; i <= n; i++)
								if (i != init)
									printf(" -> %d", i);

							for (i = 1; i<init; i++)
							{
								if (i != init)
									printf(" -> %d", i);
								last = i;
							}
							for (i = init + 1; i <= n; i++)
								if (max < process[i].identifier && process[i].live == 1)
								{
									cordinator = i;
									max = process[i].identifier;
								}

							for (i = 1; i <= init; i++)
								if (max < process[i].identifier && process[i].live == 1)
								{
									cordinator = i;
									max = process[i].identifier;
								}

							max = -99;
							printf("\n\n NEW CO-ORDINATOR IS=P%d", cordinator);
							break;
						}
					}
			}
			break;
		case 2:
			printf("\n Enter process id to activate");
			scanf("%d", &id);
			if (process[id].live == 1)
				printf("\n Process %d is already active", id);
			else
			{
				process[id].live = 1;
				printf("\n Process %d activated", id);
				if(process[id].identifier > process[cordinator].identifier)
				{
					printf("\n NEW CO-ORDINATOR IS=P%d\n\n", id);
					cordinator=id;
				}
			}
			break;
		case 3:
			display();
			break;
		case 4:
			break;
		}
	}
}

void main()
{
	int ch, i, c;

	clrscr();

	printf("\n Enter P%d process live or not(0/1)", i);
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{	
		printf("\nEnter P%d process live or not(0/1)", i);
		scanf("%d", &process[i].live);
		printf("\nEnter P%d process identifier", i);
		scanf("%d ", &process[i].identifier);
	}
	display();
	ring();
	getch();
}
