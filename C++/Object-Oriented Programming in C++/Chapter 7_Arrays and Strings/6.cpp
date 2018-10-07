#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Suit {hearts = 3, diamonds, clubs, spades};

const int ace = 1;
const int jack = 11;
const int queen = 12;
const int king = 13;

class Cards
{
private:
    int number;
    Suit suit;

public:
    Cards()
    {}

    void set_detial(int n, Suit s)
    {
        number = n;
        suit = s;
    }

    void display()
    {
        if (number >= 2 && number <= 10)
            cout << setw(2) << number;
        else
            switch (number)
            {
            case ace:
                cout << setw(2) << "A";
                break;
            case jack:
                cout << setw(2) << "J";
                break;
            case queen:
                cout << setw(2) << "Q";
                break;
            case king:
                cout << setw(2) << "K";
                break;
            }

        cout << static_cast<char>(suit);
        /*
        switch(suit)
        {
        case clubs:
            cout << char(5);
            break;
        case diamonds:
            cout << char(4);
            break;
        case hearts:
            cout << char(3);
            break;
        case spades:
            cout << char(6);
            break;
        }
        */
    }
};

int main()
{
    Cards deck[52], temp, players[4][13];
    int i, j, p, no;
    int num;
    Suit su;

    for (i = 0; i < 52; i++)
    {
        num = (i%13) + 1;
        su = Suit(i/13 + 3);
        deck[i].set_detial(num, su);
    }

    cout << "Ordered deck:" << endl;
    for (i = 0; i < 52; i++)
    {
        deck[i].display();
        cout << "  ";
        if ((i + 1)%13 == 0)
            cout << endl;
    }

    srand(time(NULL));
    for (i = 0; i < 52; i++)
    {
        j = rand()%52;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    //cout << endl << "Shuffled deck:" << endl;
    for (p = 0, no = 0, i = 0; i < 52; i++)
    {
        /*
        deck[i].display();
        cout << "  ";
        if ((i + 1)%13 == 0)
            cout << endl;
        */

        players[p][no] = deck[i];
        p++;
        if (p%4 == 0)
        {
            p = 0;
            no++;
        }
    }

    for (i = 0; i < 4; i++)
    {
        cout << endl << "Player " << i + 1 << "\'s deck:" << endl;
        for (j = 0; j < 13; j++)
        {
            players[i][j].display();
            cout << "  ";
        }
        cout << endl;
    }

    return 0;
}
