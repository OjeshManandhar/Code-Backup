#include <iostream>

using namespace std;

long unsigned int hms_to_secs(const int hrs, const int mins, const int secs);

int main()
{
	int h, m, s;
	char ch;

	while (1)
	{
		cout << "Enter time [HH:MM:SS AND 00:00:00 TO STOP]: ";
		cin >> h >> ch >> m >> ch >> s;

		if (h == 0 && m == 0 && s == 0)
		{
			cout << endl;
			break;
		}
		cout << endl << "Equivalent time in seconds is: " << hms_to_secs(h, m, s) << '.' << endl << endl;
	}

	system("pause");
	return 0;
}

long unsigned int hms_to_secs(const int hrs, const int mins, const int secs)
{
	return (hrs * 3600 + mins * 60 + secs);
}
