#include <iostream>

using namespace std;

int main()
{
	struct fraction
	{
		int num, den;
	}frac1, frac2, ans;
	char ch, op;

	cout << "Enter operation: ";
	cin >> frac1.num >> ch >> frac1.den >> op >> frac2.num >> ch >> frac2.den;

	switch (op)
	{
	case '+':
		ans.num = frac1.num*frac2.den + frac1.den*frac2.num;
		ans.den = frac1.den*frac2.den;
		break;
	case '-':
		ans.num = frac1.num*frac2.den - frac1.den*frac2.num;
		ans.den = frac1.den*frac2.den;
		break;
	case '*':
		ans.num = frac1.num*frac2.num;
		ans.den = frac1.den*frac2.den;
		break;
	case '/':
		ans.num = frac1.num*frac2.den;
		ans.den = frac1.den*frac2.num;
		break;
	default:
		cout << "Wrong Imput" << endl;
	}
	cout << endl << "Answer = " << ans.num << " / " << ans.den << '.' << endl;

	system("pause");
	return 0;
}