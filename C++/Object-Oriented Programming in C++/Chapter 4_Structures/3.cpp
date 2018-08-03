#include <iostream>

using namespace std;

int main()
{
	struct Distance
	{
		int feet;
		float inches;
	};
	struct volume
	{
		Distance length;
		Distance breadth;
		Distance height;
	};
	float l, b, h;

	volume room = { {16, 3.5}, {12, 6.25}, {8, 1.75} };

	l = room.length.feet + room.length.inches / 12.0;
	b = room.breadth.feet + room.breadth.inches / 12.0;
	h = room.height.feet + room.height.inches / 12.0;
	
	cout << "volume of the room is: " << l*b*h << " square feet." << endl;

	system("pause");
	return 0;
}