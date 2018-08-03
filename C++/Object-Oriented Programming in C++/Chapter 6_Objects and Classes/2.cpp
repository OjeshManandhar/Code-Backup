#include <iostream>
#include <conio.h>

using namespace std;

class toolBooth
{
private:
	unsigned int total_cars;
	double amount;

public:
	toolBooth() : total_cars(0), amount(0)
	{}

	void display() const
	{
		cout << endl << endl << "Total cars passed: " << total_cars << endl
			<< "Total cash collected: " << amount << endl << endl;
	}

	void payingCar()
	{
		total_cars++;
		amount += 0.5;
	}

	void nopayCar()
	{
		total_cars++;
	}
};

int main()
{
	toolBooth data;
	char ch;

	cout << "Press 'P' for paying car and 'N' for non-paying car or ESC to exit." << endl;
	do
	{
		cout << endl << "Press a key: ";
		ch = _getche();
		if (ch >= 'a' && ch <= 'z')
			ch -= 32;

		switch (ch)
		{
		case 'P':
			data.payingCar();
			break;
		case 'N':
			data.nopayCar();
			break;
		case 27:
			data.display();
			break;
		default:
			cout << endl << "Wrong intput";
		}
	} while (ch != 27);

	system("pause");
	return 0;
}