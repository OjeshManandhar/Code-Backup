#include <iostream>

using namespace std;

void swap(int &a, int&b);

int main()
{
	int a = 5, b = 3;

	cout << "Before swapping:" << endl
		<< "a = " << a << endl
		<< "b = " << b << endl;

	swap(a, b);

	cout << endl << "After swapping:" << endl
		<< "a = " << a << endl
		<< "b = " << b << endl;
	
	system("pause");
	return 0;
}

void swap(int &a, int&b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}