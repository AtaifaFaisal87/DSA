
#include <iostream>
using namespace std;

int ACKERMANN(int x, int y)
{
    if (x == 0)
    {
        return y + 1;
    }

    else if (x > 0 && y == 0)
    {
        return ACKERMANN(x - 1, 1);
    }

    else
    {
        return ACKERMANN(x - 1, ACKERMANN(x, y - 1));
    }
}

int main()
{
    int x, y;

    cout << "Enter x: ";
    cin >> x;

    cout << "Enter y: ";
    cin >> y;

    cout << "Ackermann Function = " << ACKERMANN(x, y);

    return 0;
}
