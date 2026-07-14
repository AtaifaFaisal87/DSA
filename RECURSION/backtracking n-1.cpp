#include <iostream>
using namespace std;

void linearSeries(int i,int n)
{
    if (i > n )
    {
        return;
    }


    linearSeries(i + 1,5);
    
    cout << i << endl;
}

int main()
{
    linearSeries(1,5);

    
    return 0;
}