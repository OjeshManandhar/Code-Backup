#include <iostream>

using namespace std;

int main()
{
	struct sterling
	{
		int pounds, shillings, pence;
	}money;
	float decimal_pounds, dec;

	cout << "Enter amount in decimal pounds: ";
	cin >> decimal_pounds;

	money.pounds = static_cast<int>(decimal_pounds);
	dec = decimal_pounds - money.pounds;
	dec *= 20;
	money.shillings = static_cast<int>(dec);
	dec -= money.shillings;
	money.pence = dec * 12;

	cout << endl << "Eqiuivalent in old notation = \x9c" << money.pounds << '.' << money.shillings << '.' << money.pence << endl;

	system("pause");
	return 0;
}