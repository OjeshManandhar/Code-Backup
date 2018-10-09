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

	time operator +(time t) const
	{
	    time temp;

	    temp.secs = secs + t.secs;
	    if (temp.secs >= 60)
        {
            temp.secs -= 60;
            temp.mins += 1;
        }

	    temp.mins += mins + t.mins;
	    if (temp.mins >= 60)
        {
            temp.mins -= 60;
            temp.hours += 1;
        }

        temp.hours += hours + t.hours;

        return temp;
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

	sum = t1 + t2;

	cout << endl << "Time in sum after adding t1 and t2 is ";
	sum.display();
	cout << endl;

	return 0;
}
