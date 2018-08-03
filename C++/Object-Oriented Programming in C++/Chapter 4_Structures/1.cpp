#include <iostream>

using namespace std;

int main()
{
	struct phone
	{
		int area_code;
		int exchange;
		int number;
	}your_number;

	phone my_number = { 212, 767, 8900 };

	cout << "Enter your area code, exchange, and number: ";
	cin >> your_number.area_code >> your_number.exchange >> your_number.number;

	cout << endl << "My number is (" << my_number.area_code << ") " << my_number.exchange << " - " << my_number.number << endl;
	cout << "My number is (" << your_number.area_code << ") " << your_number.exchange << " - " << your_number.number << endl;

	system("pause");
	return 0;
}