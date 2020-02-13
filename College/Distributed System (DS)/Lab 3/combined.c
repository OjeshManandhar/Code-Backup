#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <process.h>

struct proc
{
	int live;
	int identifier;
} process[10];

int n, cordinator;

/* DISPLAY PROCESSES */
void display()
{
	int i;
	printf("\nPROCESSES ARE\n\n");

	printf("Processes\t");
	for(i = 1; i <= n; i++)
        if (i == cordinator)
            printf("P%d *\t", i);
        else
            printf("P%d\t", i);

	printf("\nlive\t\t");
	for (i = 1; i <= n; i++)
		printf("%d\t", process[i].live);

	printf("\nidentifier\t");
	for (i = 1; i <= n; i++)
		printf("%d\t", process[i].identifier);
}

/* BULLY ALGORITHM */
void bully(int init)
{
    int i, max;
    for (i = 1; i <= n; i++)
        if(i != init && process[i].identifier > process[init].identifier)
            printf("\n Election MSG sent from %d to %d", init, i);

    for (i = 1; i <= n; i++)
        if (i != init)
            if (process[i].identifier > process[init].identifier && process[i].live != 0)
                printf("\n OK from %d to %d", i, init);

    for (i = 1, max = -99; i <= n; i++)
        if (max < process[i].identifier && process[i].live != 0)
        {
            cordinator = i;
            max = process[i].identifier;
        }

    printf("\n\n NEW CO-ORDINATOR IS = P%d", cordinator);
}

/* RING ALGORITHM*/
void ring(int init)
{
    int i, last, max;

    last = init;

    printf("\nElection MSG sent from = %d", last);
    for (i = init + 1; i <= n; i++)
        if (i != init)
            printf(" -> %d", i);

    for (i = 1; i < init; i++)
    {
        if (i != init)
            printf(" -> %d", i);
        last = i;
    }

    max = -99;
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

    printf("\n\n NEW CO-ORDINATOR IS = P%d", cordinator);
}

/* MENU */
void menu(int choice)
{
	int ch, id, init;

	while (ch != 4)
	{
	    if (choice == 1)
            printf("\n\n\n *** BULLY ALGORITHM ***");
        else
            printf("\n\n\n *** RING ALGORITHM ***");
		printf("\n1.Crash a Process\n2.Activate Process\n3.Display\n4.Exit");
		printf("\nENTER UR CHOICE: ");
		scanf("%d", &ch);

		switch(ch)
		{
		case 1:
			printf("\n Enter the process id to crash: ");
			scanf("%d", &id);

			if (process[id].live == 0)
				printf("\nAlready crashed process");
			else
			{
				process[id].live =  0;
				printf("\nProcess P%d is crashed", id);
				if (id == cordinator)
					while (1)
					{
						printf("\nEnter process id who inflates election: ");
						scanf("%d", &init);
						if (process[init].live == 0)
							printf("\nThe selected process is crashed");
						else
						{
						    if (choice == 1)
                                bully(init);
                            else
                                ring(init);
							break;
						}
					}
			}
			break;
		case 2:
			printf("\n Enter process id to activate: ");
			scanf("%d", &id);
			if(process[id].live == 1)
				printf("\n Process %d is already active", id);
			else
			{
				process[id].live = 1;
				printf("\n Process %d activated", id);
			}
			if (process[id].identifier > process[cordinator].identifier)
			{
				cordinator = id;
				printf("\n NEW CO-ORDINATOR IS=P%d\n\n",id);
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

int main()
{
	int i, choice, maxId = -99;

	system("cls");

	printf("Choose and algorithm to use:\n1. Bully\n2. Ring\n");
	do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }while (choice != 1 && choice != 2);

	printf("\nENTER NO. OF PROCESSES: ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf("\nEnter P%d process live or not(0/1): ", i);
		scanf("%d", &process[i].live);
		printf("Enter P%d process identifier: ", i);
		scanf("%d",&process[i].identifier);

		if (process[i].identifier > maxId && process[i].live)
        {
            cordinator = i;
            maxId = process[i].identifier;
        }
	}

	display();

	menu(choice);

	return 0;
}
