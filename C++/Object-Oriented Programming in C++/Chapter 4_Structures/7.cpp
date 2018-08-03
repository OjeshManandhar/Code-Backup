#include <iostream>

using namespace std;

int main()
{
	enum etype
	{
		laborer = 'l', secretary = 's', manager = 'm', accountant = 'a', executive = 'e', researcher = 'r'
	};
	struct date
	{
		int day, mon, year;
	};
	struct employee
	{
		int no;
		float com;
		etype type;
		date first_day;
	}e1, e2, e3;
	char ch;

	cout << "Enter data of first employee" << endl;
	cout << "Enter employee's number: ";
	cin >> e1.no;
	cout << "Enter compensation of the employee: $";
	cin >> e1.com;
	cout << "Enter employee type (first letter only)" << endl
		<< "\tlabour, secretart, manager" << endl
		<< "\taccountant, executive, researcher: ";
	cin >> ch;
	e1.type = static_cast<etype>(ch);
	cout << "Enter date of first employment [DD/MM/YYYY]: ";
	cin >> e1.first_day.day >> ch >> e1.first_day.mon >> ch >> e1.first_day.year;

	cout << endl << "Enter data of second employee" << endl;
	cout << "Enter employee's number: ";
	cin >> e2.no;
	cout << "Enter compensation of the employee: $";
	cin >> e2.com;
	cout << "Enter employee type (first letter only)" << endl
		<< "\tlabour, secretart, manager" << endl
		<< "\taccountant, executive, researcher: ";
	cin >> ch;
	e2.type = static_cast<etype>(ch);
	cout << "Enter date of first employment [DD/MM/YYYY]: ";
	cin >> e2.first_day.day >> ch >> e2.first_day.mon >> ch >> e2.first_day.year;

	cout << endl << "Enter data of third employee" << endl;
	cout << "Enter employee's number: ";
	cin >> e3.no;
	cout << "Enter compensation of the employee: $";
	cin >> e3.com;
	cout << "Enter employee type (first letter only)" << endl
		<< "\tlabour, secretart, manager" << endl
		<< "\taccountant, executive, researcher: ";
	cin >> ch;
	e3.type = static_cast<etype>(ch);
	cout << "Enter date of first employment [DD/MM/YYYY]: ";
	cin >> e3.first_day.day >> ch >> e3.first_day.mon >> ch >> e3.first_day.year;

	cout << endl << "Employee No: " << e1.no << '.' << endl;
	cout << "Compensation: $" << e1.com << '.' << endl;
	cout << "Type: ";
	switch (e1.type)
	{
	case 'l':
		cout << "Laborer." << endl;
		break;
	case 's':
		cout << "Secretary." << endl;
		break;
	case 'm':
		cout << "Manager." << endl;
		break;
	case 'a':
		cout << "Accountant." << endl;
		break;
	case 'e':
		cout << "Executive." << endl;
		break;
	case 'r':
		cout << "Researcher." << endl;
		break;
	}
	cout << "Date of first employment: " << e1.first_day.day << '/' << e1.first_day.mon << '/' << e1.first_day.year << '.' << endl;

	cout << endl << "Employee No: " << e2.no << '.' << endl;
	cout << "Compensation: $" << e2.com << '.' << endl;
	cout << "Type: ";
	switch (e2.type)
	{
	case 'l':
		cout << "Laborer." << endl;
		break;
	case 's':
		cout << "Secretary." << endl;
		break;
	case 'm':
		cout << "Manager." << endl;
		break;
	case 'a':
		cout << "Accountant." << endl;
		break;
	case 'e':
		cout << "Executive." << endl;
		break;
	case 'r':
		cout << "Researcher." << endl;
		break;
	}
	cout << "Date of first employment: " << e2.first_day.day << '/' << e2.first_day.mon << '/' << e2.first_day.year << '.' << endl;

	cout << endl << "Employee No: " << e3.no << '.' << endl;
	cout << "Compensation: $" << e3.com << '.' << endl;
	cout << "Type: ";
	switch (e3.type)
	{
	case 'l':
		cout << "Laborer." << endl;
		break;
	case 's':
		cout << "Secretary." << endl;
		break;
	case 'm':
		cout << "Manager." << endl;
		break;
	case 'a':
		cout << "Accountant." << endl;
		break;
	case 'e':
		cout << "Executive." << endl;
		break;
	case 'r':
		cout << "Researcher." << endl;
		break;
	}
	cout << "Date of first employment: " << e3.first_day.day << '/' << e3.first_day.mon << '/' << e3.first_day.year << '.' << endl;

	system("pause");
	return 0;
}