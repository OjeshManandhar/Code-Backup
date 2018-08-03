#include <iostream>

#include <conio.h>
#include <windows.h>

using namespace std;

void cls(int = 0, int = 0, int = 0, int = 0);
void gotoxy(const short int, const short int);

int main()
{
	int i;
	for (i = 1; i < 80*25+1; i++)
	{
		cout << 'X';
	}
	_getch();
	cls(0, 0, 10, 5);
	_getch();
	cls();
	cout << "Hello World!" << endl;

	system("pause");
	return 0;
}

void cls(int top_x, int top_y, int bot_x, int bot_y)
{
	int i,j;

	if (top_x == 0 && top_y == 0 && bot_x == 0 && bot_y == 0)
	{
		system("cls");
	}
	else
	{
		for (i = top_y; i <= bot_y; i++)
		{
			for (j = top_x; j <= bot_x; j++)
			{
				gotoxy(i, j);
				cout << ' ';
			}
		}
	}
}

void gotoxy(const short int row, const short int col)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { col,row };
	SetConsoleCursorPosition(h, position);
}