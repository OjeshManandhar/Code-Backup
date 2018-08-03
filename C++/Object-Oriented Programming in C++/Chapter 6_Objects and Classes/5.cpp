#include <iostream>

using namespace std;

class date
{
private:
	int day;
	int month;
	int year;

public:
	date() : day(0), month(0), year(0)
	{}

	void getdate()
	{
		char dummychar;

		cout << "Enter date in format YY/MM/DD: ";
		cin >> year >> dummychar >> month >> dummychar >> day;
	}

	void showdate() const
	{
		cout << year << '/' << month << '/' << day << endl;
	}
};

int main()
{
	date d1;

	cout << "Date stored in d1: ";
	d1.showdate();
	cout << endl;
	d1.getdate();
	cout << endl << "Date stored in d1: ";
	d1.showdate();
	cout << endl;

	system("pause");
	return 0;
}