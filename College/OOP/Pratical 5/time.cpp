#include <iostream>

using namespace std;

class time
{
private:
    int h, m, s;
public:
    time()
    {
        h = m = s = 0;
    }
    void getdata()
    {
        char dummy;
        cout << "Enter time [HH:MM:SS]: ";
        cin >> h >> dummy >> m >> dummy >> s;
    }
    void showdata()
    {
        cout << "HH:MM:SS = " << h << ':' << m << ':' << s << endl;
    }
    void addtime(time a, time b)
    {
        h = m = s = 0;

        s = a.s + b.s;
        m += a.m + b.m + s/60;
        s %= 60;
        h += a.h + b.h +m/60;
        m %=60;
    }
    void subtime(time a, time b)
    {
        h = m = s = 0;

        s = a.s - b.s;
        if (s < 0)
        {
            s += 60;
            m--;
        }
        m += a.m - b.m;
        if (m < 0)
        {
            m += 60;
            h--;
        }
        h += a.h - b.h;
    }
};

int main()
{
    time a, b, c;

    cout << "Enter first time:" << endl;
    a.getdata();
    cout << endl << "Enter second time:" << endl;
    b.getdata();

    cout << endl << "Adding two times:" << endl;
    c.addtime(a, b);
    c.showdata();

    cout << endl << "Subtracting two times:" << endl;
    c.subtime(a, b);
    c.showdata();

    return 0;
}
/*
Output:
Enter first time:
Enter time [HH:MM:SS]: 2:30:45

Enter second time:
Enter time [HH:MM:SS]: 3:45:55

Adding two times:
HH:MM:SS = 6:16:40

Subtracting two time:
HH:MM:SS = -2:44:50
*/
