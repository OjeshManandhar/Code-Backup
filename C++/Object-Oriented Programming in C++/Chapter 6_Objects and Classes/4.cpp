#include <iostream>

using namespace std;

class employee
{
private:
	int emp_no;
	float comp;
	
public:
	void display() const;
	void get_data();
};

int main()
{
	employee e1, e2, e3;

	cout << "Enter data for employeee 1: " << endl;
	e1.get_data();
	cout << endl << "Enter data for employeee 2: " << endl;
	e2.get_data();
	cout << endl << "Enter data for employeee 2: " << endl;
	e3.get_data();
	cout << endl;

	cout << endl << "Data of employee 1:" << endl;
	e1.display();
	cout << endl << "Data of employee 2:" << endl;
	e2.display();
	cout << endl << "Data of employee 3:" << endl;
	e3.display();
	cout << endl;

	system("pause");
	return 0;
}

void employee::display() const
{
	cout << "Employee Number: " << emp_no << endl
		<< "Compensation : $" << comp << endl;
}

void employee::get_data()
{
	cout << "Enter Employee number: ";
	cin >> emp_no;
	cout << "Enter Compensation: ";
	cin >> comp;
}