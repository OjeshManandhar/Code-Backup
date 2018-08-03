#include <iostream>

using namespace std;

class trial
{
private:
	int serial;
	static int count;

public:
	trial()
	{
		count++;
		serial = count;
	}

	void put_serial() const
	{
		cout << "I am object number " << serial << '.' << endl;
	}
};

int trial::count = 0;

int main()
{
	trial t1, t2, t3;

	cout << "For t1:" << endl;
	t1.put_serial();
	cout << endl << "For t2:" << endl;
	t2.put_serial();
	cout << endl << "For t3:" << endl;
	t3.put_serial();

	system("pause");
	return 0;
}