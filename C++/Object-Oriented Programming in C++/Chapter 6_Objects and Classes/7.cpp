#include <iostream>

using namespace std;

class angle
{
private:
	int degree;
	float second;
	char dir;

public:
	angle() : degree(0), second(0), dir('E')
	{}

	angle(int d, float s, char c) : degree(d), second(s), dir(c)
	{}

	void get_data()
	{
		bool loop;
		float total;

		do
		{
			loop = false;

			cout << "Enter degrees: ";
			cin >> degree;
			cout << "Enter seconds: ";
			cin >> second;
			do
			{
				cout << "Enter direction [E / W / N / S]: ";
				cin >> dir;
				if (dir >= 'a' && dir <= 'z')
					dir -= 32;
			} while (dir != 'E' && dir != 'W' && dir != 'S' && dir != 'N');

			total = degree + second / 60;

			if (((dir == 'N' || dir == 'S') && total > 90) || (total > 180))
			{
				cout << "Wrong Input. Enter again." << endl;
				loop = true;
			}
		} while (loop == true);
	}

	void put_data() const
	{
		cout << degree << '\xF8' << second << "\' " << dir << endl;
		//'\xF8' = static_cast<char>(248)
	}
};

int main()
{
	angle a;
	char choice;

	cout << "Initial angle: ";
	a.put_data();

	do
	{
		cout << endl;
		a.get_data();
		cout << endl << "The entered angle is: ";
		a.put_data();
		do
		{
			cout << endl << "Do you want to contimue [Y/N]: ";
			cin >> choice;
			if (choice >= 'a' && choice <= 'z')
				choice -= 32;
		} while (choice != 'Y' && choice != 'N');
	} while (choice == 'Y');

	system("pause");
	return 0;
}