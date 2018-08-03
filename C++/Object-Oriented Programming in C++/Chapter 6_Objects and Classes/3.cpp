#include <iostream>

using namespace std;

class time
{
private:
	int hours;
	int mins;
	int secs;

public:
	time() : hours(0),mins(0),secs(0)
	{}

	time(int h, int m, int s) : hours(h), mins(m), secs(s)
	{}

	void display() const
	{
		cout << hours << ':' << mins << ':' << secs;
	}

	void add_time(time t1, time t2)
	{
		secs = t1.secs + t2.secs;
		if (secs >= 60)
		{
			secs -= 60;
			mins++;
		}
		mins += t1.mins + t2.mins;
		if (mins >= 60)
		{
			mins -= 60;
			hours++;
		}
		hours += t1.hours + t2.hours;
	}
};

int main()
{
	const time t1(11, 55, 35), t2(10, 45, 40);
	time sum;

	cout << "Time in t1: ";
	t1.display();
	cout << endl<< "Time in t2: ";
	t2.display();
	cout << endl << "Time in sum: ";
	sum.display();
	cout << endl;

	sum.add_time(t1, t2);

	cout << endl << "Time in sum after adding t1 and t2: ";
	sum.display();
	cout << endl;


	system("pause");
	return 0;
}