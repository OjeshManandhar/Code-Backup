#include <iostream>

using namespace std;

int power(const int n, const int p);
char power(const char n, const int p);
long power(const long n, const int p);
float power(const float n, const int p);
double power(const double n, const int p);

int main()
{
	int p = 3;
	int i = 5;
	char c = 2;
	long l = 55;
	float f = 2.5;
	double d = 3.5;

	cout << i << " ^ " << p << " = " << power(i, p) << '.' << endl;
	cout << c << " ^ " << p << " = " << power(c, p) << '.' << endl;
	cout << l << " ^ " << p << " = " << power(l, p) << '.' << endl;
	cout << f << " ^ " << p << " = " << power(f, p) << '.' << endl;
	cout << d << " ^ " << p << " = " << power(d, p) << '.' << endl;
	
	system("pause");
	return 0;
}

int power(const int n, const int p)
{
	int i, ans = 1;

	for (i = 1; i <= p; i++)
	{
		ans *= n;
	}

	return ans;
}

char power(const char n, const int p)
{
	int i;
	char ans = 1;

	for (i = 1; i <= p; i++)
	{
		ans *= n;
	}

	return ans;
}

long power(const long n, const int p)
{
	int i;
	long ans = 1;

	for (i = 1; i <= p; i++)
	{
		ans *= n;
	}

	return ans;
}

float power(const float n, const int p)
{
	int i;
	float ans = 1;

	for (i = 1; i <= p; i++)
	{
		ans *= n;
	}

	return ans;
}

double power(const double n, const int p)
{
	int i;
	double ans = 1;

	for (i = 1; i <= p; i++)
	{
		ans *= n;
	}

	return ans;
}