#include <iostream>
using namespace std;

void linearSeries(int i, int n)
{
    if (i > n)
    {
        return;
    }

    cout << i << endl;

    linearSeries(i + 1, n);
}

int main()
{
    linearSeries(1, 5);

    
    return 0;
}