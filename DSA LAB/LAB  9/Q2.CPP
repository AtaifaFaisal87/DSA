
#include <iostream>
using namespace std;

int FACTORIAL(int n)
{
    int FACT = 1;

    for (int i = 1; i <= n; i++)
    {
        FACT = FACT * i;
    }

    return FACT;
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Factorial = " << FACTORIAL(n);

    return 0;
}
