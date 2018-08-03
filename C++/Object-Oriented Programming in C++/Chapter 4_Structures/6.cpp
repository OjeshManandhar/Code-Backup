#include <iostream>

using namespace std;

int main()
{
	enum etype
	{
		laborer = 'l', secretary = 's', manager = 'm', accountant = 'a', executive = 'e', researcher = 'r'
	}choice;
	char ch;

	cout << "Enter employee type (first letter only)" << endl
		 << "	laborer, secretary, manager" << endl
		 << "	accountant, executive, researcher: ";
	cin >> ch;
	choice = static_cast<etype>(ch);

	cout << endl << "Employee type is ";
	switch (choice)
	{
	case 'l':
		cout << "laborer." << endl;
		break;
	case 's':
		cout << "secretary." << endl;
		break;
	case 'm':
		cout << "manager." << endl;
		break;
	case 'a':
		cout << "accountant." << endl;
		break;
	case 'e':
		cout << "executive." << endl;
		break;
	case 'r':
		cout << "researcher." << endl;
		break;
	}

	system("pause");
	return 0;
}