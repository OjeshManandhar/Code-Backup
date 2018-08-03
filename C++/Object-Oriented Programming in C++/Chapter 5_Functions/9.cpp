#include <iostream>

using namespace std;

struct time
{
	int hrs, mins, secs;
};

void swap(time &a, time &b);

int main()
{
	time a = { 5,26,54 };
	time b = { 2,25,52 };

	cout << "Before swapping: " << endl
		<< "a = " << a.hrs << ':' << a.mins << ':' << a.secs << endl
		<< "b = " << b.hrs << ':' << b.mins << ':' << b.secs << endl;

	swap(a, b);

	cout << endl << "After swapping: " << endl
		<< "a = " << a.hrs << ':' << a.mins << ':' << a.secs << endl
		<< "b = " << b.hrs << ':' << b.mins << ':' << b.secs << endl;
	
	system("pause");
	return 0;
}

void swap(time &a, time &b)
{
	time temp;

	temp = a;
	a = b;
	b = temp;

	/*a.hrs = a.hrs + b.hrs;
	b.hrs = a.hrs - b.hrs;
	a.hrs = a.hrs - b.hrs;

	a.mins = a.mins + b.mins;
	b.mins = a.mins - b.mins;
	a.mins = a.mins - b.mins;

	a.secs = a.secs + b.secs;
	b.secs = a.secs - b.secs;
	a.secs = a.secs - b.secs;*/
}