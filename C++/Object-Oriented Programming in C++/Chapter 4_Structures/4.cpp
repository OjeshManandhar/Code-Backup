#include <iostream>

using namespace std;

int main()
{
	struct employee
	{
		int no;
		float com;
	}e1, e2, e3;

	cout << "Enter the employee's number and complensation: ";
	cin >> e1.no >> e1.com;
	cout << "Enter teh employee's number and compensation";
	cin >> e2.no >> e2.com;
	cout << "Enter the employee's number and compensation";
	cin >> e3.no >> e3.com;

	cout << endl << "The compensation of employee " << e1.no << " is $" << e1.com << '.' << endl;
	cout << "The compensation of employee " << e2.no << " is $" << e2.com << '.' << endl;
	cout << "The compensation of employee " << e3.no << " is $" << e3.com << '.' << endl;

	system("pause");
	return 0;
}