#include <iostream>

using namespace std;

struct fraction
{
	int num, den;
};

fraction fadd(const fraction a, const fraction b);
fraction fsub(const fraction a, const fraction b);
fraction fmul(const fraction a, const fraction b);
fraction fdiv(const fraction a, const fraction b);


int main()
{
    short int flag = 0;
	fraction a, b, ans;
	char ch, op;

	cout << "Enter operation: ";
	cin >> a.num >> ch >> a.den >> op >> b.num >> ch >> b.den;

	switch (op)
	{
	case '+':
		ans = fadd(a, b);
		break;
	case '-':
		ans = fsub(a, b);
		break;
	case '*':
		ans = fmul(a, b);
		break;
	case '/':
		ans = fdiv(a, b);
		break;
	default:
	    flag = 1;
		cout << "Wrong Imput" << endl;
	}
	if (flag != 1)
        cout << endl << "Answer = " << ans.num << " / " << ans.den << '.' << endl;

	system("pause");
	return 0;
}

fraction fadd(const fraction a, const fraction b)
{
	fraction ans;

	ans.num = a.num * b.den + a.den * b.num;
	ans.den = a.den * b.den;

	return ans;
}

fraction fsub(const fraction a, const fraction b)
{
	fraction ans;

	ans.num = a.num * b.den - a.den * b.num;
	ans.den = a.den * b.den;

	return ans;
}

fraction fmul(const fraction a, const fraction b)
{
	fraction ans;

	ans.num = a.num * b.num;
	ans.den = a.den * b.den;

	return ans;
}

fraction fdiv(const fraction a, const fraction b)
{
	fraction ans;

	ans.num = a.num * b.den;
	ans.den = a.den * b.num;

	return ans;
}
