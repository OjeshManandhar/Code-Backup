#include <iostream>

using namespace std;

struct streling
{
	int pounds, shillings, pence;
};

streling get_data(void);
streling add_data(const streling a, const streling b);
void print_data(const streling a);

int main()
{
	streling a, b, ans;

	a = get_data();
	b = get_data();

	ans = add_data(a, b);

	cout << endl << "Sum = ";
	print_data(ans);

	system("pause");
	return 0;
}

streling get_data(void)
{
	streling a;
	char ch;

	cout << "Enter amount: \x9C";
	cin >> a.pounds >> ch >> a.shillings >> ch >> a.pence;

	return a;
}

streling add_data(const streling a, const streling b)
{
	streling temp;
	unsigned long int total;

	total = a.pounds*(20 * 12) + a.shillings*(12) + a.pence;
	total += b.pounds*(20 * 12) + b.shillings*(12) + b.pence;

	temp.pounds = total / (20 * 12);
	total -= temp.pounds* (20 * 12);
	temp.shillings = total / (12);
	temp.pence = total - temp.shillings * 12;

	return temp;
}

void print_data(const streling a)
{
	cout << '\x9c' << a.pounds << '.' << a.shillings << '.' << a.pence << endl;
}