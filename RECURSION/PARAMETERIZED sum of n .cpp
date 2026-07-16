#include <iostream>
using namespace std;

void sum(int n, int ans)
{
    if (n == 0)
    {
        cout << ans << endl;
        return;
    }

    sum(n - 1, ans + n);
}

int main()
{
    int n;

    cout << "ENTER N: ";
    cin >> n;

    sum(n, 0);

    return 0;
}