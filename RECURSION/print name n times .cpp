//0(n) time comp
//0(n) space comp
#include <iostream>
using namespace std;

void print(string n, int times, int i)
{

    if (i == times)
    {
        return;
    }

    cout << n << endl;

    print(n, times, i + 1);
}

int main()
{
    string name;
    int n;

    cout << "ENTER NAME:";
    cin >> name;

    cout << "HOW MANY TIMES TO PRINT:";
    cin >> n;

    print(name, n, 0);

    return 0;
}