#include <iostream>
using namespace std;

void findA(const char s[])
{
    int i = 0;
    bool found = false;

    while (s[i] != '\0')
    {
        if (s[i] == 'a')
        {
            cout << i << " ";
            found = true;
        }

        i++;
    }

    if (!found)
    {
        cout << "NO OCCURRENCE FOUND!";
    }
}

int main()
{
    char s[100];

    cout << "ENTER STRING: ";
    cin.getline(s, 100);

    cout << "INDICES OF 'a': ";
    findA(s);

    return 0;
}