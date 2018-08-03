#include <iostream>

using namespace std;

int main()
{
	struct date
	{
		int day;
		int mon;
		int year;
	}data;
	char ch;

	cout << "Enter a date [FORMAT: DD/MM/YYYY]: ";
	cin >> data.day >> ch >> data.mon >> ch >> data.year;

	cout << endl << "The date you entered is: " << data.day << '/' << data.mon << '/' << data.year << endl;

	system("pause");
	return 0;
}