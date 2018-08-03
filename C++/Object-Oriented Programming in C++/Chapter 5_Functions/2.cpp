#include <iostream>

using namespace std;

double power(const double numb, const int pow);

int main()
{
	int p;
	double n;

	cout << "Enter a number: ";
	cin >> n;
	cout << "Enter power: ";
	cin >> p;

	cout << endl << n << " to the power " << p << " is " << power(n, p) << '.' << endl;

	system("pause");
	return 0;
}

double power(const double numb, const int pow)
{
	int i;
	double ans=1;

	for (i = 1; i <= pow; i++)
	{
		ans *= numb;
	}

	return ans;
}
