#include <iostream>

using namespace std;

class student
{
private:
    int roll;
    char name[31];
    char address[31];
    static char faculty[6];

public:
    void getdata()
    {
        cout << "Enter roll: ";
        cin >> roll;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter address: ";
        cin >> address;
    }

    void showdata()
    {
        cout << endl << "Roll = " << roll << endl
             << "Name = " << name << endl
             << "Address = " << address << endl
             << "Faculty = " << faculty << endl;
    }
};

char student::faculty[6] = "BCT";

int main()
{
    student s;

    s.getdata();
    s.showdata();

    return 0;
}

/*
Output:
Enter roll: 73050
Enter name: Ojesh
Enter address: Buddhanagar

Roll = 73050
Name = Ojesh
Address = Buddhanagar
Faculty = BCT
*/
