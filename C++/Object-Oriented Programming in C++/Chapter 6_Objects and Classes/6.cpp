#include <iostream>

using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };

class date
{
private:
	int day;
	int mon;
	int year;

public:
	void getdata()
	{
		char dummychar;

		cin >> year >> dummychar >> mon >> dummychar >> day;
	}

	void showdate() const
	{
		cout << year << '/' << mon << '/' << day << '.' << endl;
	}
};

class employee
{
private:
	int emp_no;
	float sal;
	date jd;
	etype e;

public:
	void getemploy()
	{
		char ch;

		cout << "Enter Employee Number: ";
		cin >> emp_no;
		cout << "Enter Salary: ";
		cin >> sal;
		cout << "Enter Date of Joining [YYYY/MM/DD]: ";
		jd.getdata();
		cout << "Enter Employee's type (first letter only)" << endl
			<< "	Laborer, Secretary, Manager" << endl
			<< "	Accountant, Executive, Researcher: ";
		cin >> ch;
		if (ch >= 'A' && ch <= 'Z')
			ch += 32;
		e = static_cast<etype>(ch);
	}

	void putemploy() const
	{
		cout << "Employee Number: " << emp_no << endl;
		cout << "Salary: " << sal << endl;
		cout << "First Employment: ";
		jd.showdate();
		cout << "Type: ";
		switch (e)
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
	}
};

int main()
{
	employee e1, e2, e3;

	cout << "Enter data of first employee: " << endl;
	e1.getemploy();
	cout << endl << "Enter data of second employee: " << endl;
	e2.getemploy();
	cout << endl << "Enter data of third employee: " << endl;
	e3.getemploy();
	
	cout << endl << endl << "Data of first employee: " << endl;
	e1.putemploy();
	cout << endl << "Data of second employee: " << endl;
	e2.putemploy();
	cout << endl << "Data of third employee: " << endl;
	e3.putemploy();

	cout << endl;

	system("pause");
	return 0;
}