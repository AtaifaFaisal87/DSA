#include <iostream>
using namespace std;

void linearSeries(int i, int n)
{
    if (i < n)
    {
        return;
    }

    linearSeries(i - 1, n);

    cout << i << endl;
}

int main()
{
    linearSeries(5, 1);

    return 0;
}