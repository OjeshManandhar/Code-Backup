#include <iostream>

using namespace std;

class Queue
{
private:
    static const int MAXSIZE = 10;
    int head, tail;
    int arr[MAXSIZE];

public:
    Queue(): head(-1), tail(-1)
    {
        int i;

        for (i = 0; i < MAXSIZE; i++)
            arr[i] = 0;
    }

    void put(int x)
    {
        tail = (tail + 1)%MAXSIZE;
        arr[tail] = x;

        if (head == -1)
            head = 0;
    }

    int get()
    {
        int temp = arr[head];

        if (head == tail)
            head = tail = -1;
        else
            head = (head + 1)%MAXSIZE;

        return temp;
    }
};

int main()
{
    Queue q;

    q.put(11);
    q.put(22);
    cout << "1: " << q.get() << endl;
    cout << "2: " << q.get() << endl;
    q.put(33);
    q.put(44);
    q.put(55);
    q.put(66);
    cout << "3: " << q.get() << endl;
    cout << "4: " << q.get() << endl;
    cout << "5: " << q.get() << endl;
    cout << "6: " << q.get() << endl;

    return 0;
}
