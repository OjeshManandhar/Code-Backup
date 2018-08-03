#include <iostream>

using namespace std;

class angle
{
private:
	int degrees;
	float seconds;
	char dir;

public:
	angle() : degrees(0), seconds(0.0), dir('E')
	{}

	void get_angle()
	{
		cout << "Enter Degrees: ";
		cin >> degrees;
		do
		{
			cout << "Enter Seconds: ";
			cin >> seconds;
		} while (seconds > 60);

		if (seconds == 60)
		{
			seconds = 0;
			degrees++;
		}

		do
		{
			cout << "Enter Direction: ";
			cin >> dir;
			if (dir >= 'a' && dir <= 'z')
				dir -= 32;
		} while (dir != 'W' && dir != 'E' && dir != 'S' && dir != 'N');
	}

	void put_angle() const
	{
		cout << degrees << '\xF8' << seconds << "\' " << dir << endl;
	}

	void get_var(int &d, float &s, char &c)
	{
		d = degrees;
		s = seconds;
		c = dir;
	}
};

class ship
{
private:
	static int count;
	angle longitude;
	angle latitude;
	int serial;

public:
	ship()
	{
		count++;
		serial = count;
	}

	void get_ship()
	{
		int a;
		float b, total;
		char c;

		do
		{
			cout << "Enter LONGITUDE:" << endl;
			longitude.get_angle();
			longitude.get_var(a, b, c);
			total = a * 60 + b;
			cout << endl;
		} while (total > 180 * 60 || ((c != 'W' && c != 'E') && (c == 'N' || c == 'S')));
		do
		{
			cout << "Enter LATITUDE:" << endl;
			latitude.get_angle();
			latitude.get_var(a, b, c);
			total = a * 60 + b;
			cout << endl;
		} while (total > 90 * 60 || ((c != 'N' && c != 'S') && (c == 'E' || c == 'W')));
	}

	void put_ship() const
	{
		cout << "Serial: " << serial << endl;
		cout << "Longitude: ";
		longitude.put_angle();
		cout << "Latitude: ";
		latitude.put_angle();
	}
};

int ship::count = 0;

int main()
{
	ship s1, s2, s3;

	cout << "Enter data for SHIP_1:\n" << endl;
	s1.get_ship();
	cout << "Enter data for SHIP_2:\n" << endl;
	s2.get_ship();
	cout << "Enter data for SHIP_3:\n" << endl;
	s3.get_ship();

	cout << endl << "Entered datas are:" << endl;
	cout << "SHIP_1:" << endl;
	s1.put_ship();
	cout << endl << "SHIP_2:" << endl;
	s2.put_ship();
	cout << endl << "SHIP_3:" << endl;
	s3.put_ship();

	system("pause");
	return 0;
}