#include <iostream>

using namespace std;

class fraction
{
private:
	int num;
	int den;

public:
	fraction() : num(0), den(0)
	{}

	void get_frac()
	{
		char dummychar;

		cout << "Enter a fraction: ";
		cin >> num >> dummychar >> den;
	}

	void put_frac() const
	{
		cout << num << " / " << den << endl;
	}

	void add_frac(fraction frac1, fraction frac2)
	{
		num = frac1.num*frac2.den + frac1.den*frac2.num;
		den = frac1.den*frac2.den;
	}
};

int main()
{
	fraction f1, f2, sum;
	char choice;

	do
	{
		f1.get_frac();
		f2.get_frac();
		cout << endl;

		sum.add_frac(f1, f2);
		cout << "Sum = ";
		sum.put_frac();

		cout << endl;
		do
		{
			cout << "Add another fraction [Y/N]: ";
			cin >> choice;
			if (choice >= 'a' && choice <= 'z')
				choice -= 32;
		} while (choice != 'Y' && choice != 'N');
		cout << endl;
	} while (choice == 'Y');

	system("pause");
	return 0;
}