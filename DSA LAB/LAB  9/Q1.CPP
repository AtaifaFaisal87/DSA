
#include <iostream>
using namespace std;

int FACTORIAL(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * FACTORIAL(n - 1);
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Factorial = " << FACTORIAL(n);

    return 0;
}
