#include <iostream>
using namespace std;

void linearSeries(int i)
{
    if (i < 1 )
    {
        return;
    }


    linearSeries(i - 1);
    
    cout << i << endl;
}

int main()
{
    linearSeries(5);

    
    return 0;
}