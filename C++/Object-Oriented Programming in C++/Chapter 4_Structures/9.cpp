#include <iostream>

using namespace std;

int main()
{
	struct time
	{
		int hrs, min, sec;
	}t;
	int total_secs;
	char ch;

	cout << "Enter time [HH:MM:SS]: ";
	cin >> t.hrs >> ch >> t.min >> ch >> t.sec;

	total_secs = t.hrs * 3600 + t.min * 60 + t.sec;

	cout << endl << "Total seconds: " << total_secs << '.' << endl;

	system("pause");
	return 0;
}