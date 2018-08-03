#include <iostream>

using namespace std;

void zeroSmaller(int &a, int&b);

int main()
{
	int a, b;

	cout << "Enter a number: ";
	cin >> a;
	cout << "Enter another number: ";
	cin >> b;

	cout << endl << "smaller number has been change to zero." << endl;
	zeroSmaller(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	system("pause");
	return 0;
}

void zeroSmaller(int &a, int&b)
{
	if (a < b)
	{
		a = 0;
	}
	else if (b < a)
	{
		b = 0;
	}
}