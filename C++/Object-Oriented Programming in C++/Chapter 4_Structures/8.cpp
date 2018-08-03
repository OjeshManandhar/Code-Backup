#include <iostream>

using namespace std;

int main()
{
	struct fraction
	{
		int num;
		int den;
	}frac1, frac2, ans;
	char ch;

	cout << "Enter first fraction: ";
	cin >> frac1.num >> ch >> frac1.den;
	cout << "Enter second fraction: ";
	cin >> frac2.num >> ch >> frac2.den;

	ans.num = frac1.num*frac2.den + frac1.den*frac2.num;
	ans.den = frac1.den*frac2.den;

	cout << "Sum = " << ans.num << '/' << ans.den << '.' << endl;

	system("pause");
	return 0;
}