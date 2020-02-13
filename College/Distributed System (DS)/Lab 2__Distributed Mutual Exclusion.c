#include <stdio.h>
#include <conio.h>
#include <time.h>

int main()
{
	int cs = 0, pro = 0, run = 5;
	char key = 'a';
	time_t t1, t2;

	printf("Press a key(except q) to enter a process into critical section.\n");
	printf("Press q at any time to exit.\n");
	t1 = time(NULL) - run;
	while (key != 'q')
	{
		while (!kbhit())
			if (cs != 0)
			{
				t2 = time(NULL);
				if(t2 - t1 > run)
				{
					printf("Process %d exits critical section.\n", pro - 1);
					cs = 0;
				}
			}

		key = getch();
		if (key != 'q')
		{
			if(cs != 0)
				printf("Error: Another process is currently executing critical section. Please wait till its execution is over.\n");
			else
			{
				printf("Process %d entered critical section\n", pro);
				cs = 1;
				pro++;
				t1 = time(NULL);
			}
		}
	}

	return 0;
}

/*
Output
Press a key (except q) to enter a process into critical section. Press q at any time to exit.
Process 0 entered critical section.
Error: Another process is currently executing critical section.
Please wait till its execution Is Over.
Process 0 exits critical section.
Process 1 entered critical section.
Process 1 exits critical section.
Process 2 entered critical section.
Error: Another process is currently executing critical section.
Please wait till its execution is over.
Process 2 exits critical section.
*/
