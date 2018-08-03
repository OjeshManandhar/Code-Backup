#include <iostream>

using namespace std;

int main()
{
	struct time
	{
		int hrs, min, sec;
	}t1, t2, sum;
	int total_time, rem;
	char dummy;

	cout << "Enter first time [HH:MM:SS]: ";
	cin >> t1.hrs >> dummy >> t1.min >> dummy >> t1.sec;
	total_time = t1.hrs * 3600 + t1.min * 60 + t1.sec;
	cout << "Enter second time [HH:MM:SS]: ";
	cin >> t2.hrs >> dummy >> t2.min >> dummy >> t2.sec;
	total_time += t2.hrs * 3600 + t2.min * 60 + t2.sec;

	sum.hrs = total_time / 3600;
	total_time -= sum.hrs * 3600;
	sum.min = total_time / 60;
	sum.sec = total_time - sum.min * 60;

	cout << endl << "Sum  = " << sum.hrs << ':' << sum.min << ':' << sum.sec << endl;

	system("pause");
	return 0;
}