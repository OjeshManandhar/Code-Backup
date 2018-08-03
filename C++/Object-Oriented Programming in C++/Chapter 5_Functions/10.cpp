#include <iostream>

using namespace std;

int count_global = 0;

void demo_func_global(void);
int demo_func_static(void);

int main()
{
	int x;
	char ch;

	while (1)
	{
		cout << "Call The Function [Y/N]: ";
		cin >> ch;

		if (ch == 'y' || ch == 'Y')
		{
			demo_func_global();
			x = demo_func_static();
		}
		else
		{
			break;
		}
	}
	
	cout << endl << "demo_func_global is called " << count_global << " times." << endl;
	cout << "demo_func_static is called " << x << " times." << endl;

	system("pause");
	return 0;
}

void demo_func_global(void)
{
	count_global++;
}

int demo_func_static(void)
{
	static int count_static = 0;

	count_static++;

	return count_static;
}
