#include <iostream>

using namespace std;

class Int
{
private:
	int n;

public:
	Int() : n(0)
	{}

	Int(int i) : n(i)
	{}

	void display() const
	{
		cout << n;
	}

	void add_Int(Int a, Int b)
	{
		n = a.n + b.n;
	}
};

int main()
{
	Int a(9), b = 5, sum;

	cout << "Value in a = ";
	a.display();
	cout << endl << "Value in b = ";
	b.display();
	cout << endl << "Value in sum = ";
	sum.display();
	cout << endl;

	sum.add_Int(a, b);

	cout << endl << "Value of sum after adding a ad b = ";
	sum.display();
	cout << endl;

	system("pause");
	return 0;
}