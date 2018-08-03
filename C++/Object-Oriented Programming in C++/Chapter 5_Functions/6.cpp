#include <iostream>

using namespace std;

struct time
{
	int hrs, mins, secs;
};

unsigned long int time_to_secs(const time t);
time secs_to_time(const unsigned long int total_secs);

int main()
{
	unsigned long int total_secs;
	char ch;
	time t1, t2, ans;
	
	cout << "Enter a time [HH:MM:SS]: ";
	cin >> t1.hrs >> ch >> t1.mins >> ch >> t1.secs;
	total_secs = time_to_secs(t1);
	cout << "Enter another time [HH:MM:SS]: ";
	cin >> t2.hrs >> ch >> t2.mins >> ch >> t2.secs;
	total_secs += time_to_secs(t2);
	ans = secs_to_time(total_secs);

	cout << endl << "Total time is " << ans.hrs << ':' << ans.mins << ':' << ans.secs << '.' << endl;

	system("pause");
	return 0;
}

unsigned long int time_to_secs(const time t)
{
	return (t.hrs * 3600 + t.mins * 60 + t.secs);
}

time secs_to_time(const unsigned long int total_secs)
{
	unsigned int rem;
	time ans;

	ans.hrs = total_secs / 3600;
	rem = total_secs - ans.hrs * 3600;
	ans.mins = rem / 60;
	ans.secs = rem - ans.mins * 60;

	return ans;
}
