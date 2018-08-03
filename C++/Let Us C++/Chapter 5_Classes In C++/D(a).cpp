#include <iostream>

using namespace std;

class rectangle
{
private:
	int len, br;

public:
	rectangle()
	{
		len = br = 0;
	}

	rectangle(int l)
	{
		len = br = l;
	}

	rectangle(int l, int b)
	{
		len = l;
		br = b;
	}

	void getdata()
	{
		cout << "Enter length and Breadth: ";
		cin >> len >> br;
	}

	void setdata(int l, int b)
	{
		len = l;
		br = b;
	}

	void displaydata()
	{
		cout << "Length = " << len << endl
			<< "Breadth = " << br << endl;
	}

	void area_peri()
	{
		int a, p;

		a = len*br;
		p = (len + br) * 2;

		cout << "Area = " << a << endl
			<< "Perimeter = " << p << endl;
	}

	/*rectangle operator = (rectangle &r)
	{
	len = r.len;
	br = r.br;

	return rectangle(len, br);
	}*/

	rectangle & operator = (rectangle &r)
	{
		len = r.len;
		br = r.br;

		return *this;
	}

	/*rectangle operator = (int i)
	{
	len = br = i;

	return rectangle(len, br);
	}*/

	rectangle & operator = (int i)
	{
		len = br = i;

		return *this;
	}
};

int main()
{
	rectangle r1, r2, r3 = 9, r4, r5(6, 7);
	//mathiko defination ma r3 ra r5 le constructor use garxa|

	r1 = 3; //yesle operator overloading use garxa|

	cout << "Rectangle r1" << endl;
	r1.displaydata();

	cout << endl << "Rectangle r2" << endl;
	r2.displaydata();

	cout << endl << "Rectangle r3" << endl;
	r3.displaydata();

	r4 = r3;

	cout << endl << "Rectangle r4" << endl;
	r4.displaydata();

	cout << endl << "Rectangle r5" << endl;
	r5.displaydata();

	system("pause");
	return 0;
}