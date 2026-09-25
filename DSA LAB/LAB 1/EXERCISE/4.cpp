#include <iostream>
using namespace std;

int myLength(const char s[])
{
    int len = 0;

    while (s[len] != '\0')
    {
        len++;
    }

    return len;
}

void substring(const char s[], int ip, int len, char dest[])
{
    int n = myLength(s);

    if (ip < 0 || ip >= n)
    {
        cout << "INVALID STARTING POSITION!" << endl;
        return;
    }

    if (len < 0 || ip + len > n)
    {
        cout << "INVALID LENGTH!" << endl;
        return;
    }

    int count = 0;

    while (count < len)
    {
        dest[count] = s[ip];
        count++;
        ip++;
    }

    dest[count] = '\0';
}

int main()
{
    char s[100];
    char dest[100];

    int ip, len;

    cout << "ENTER STRING: ";
    cin.getline(s, 100);

    cout << "ENTER STARTING POSITION: ";
    cin >> ip;

    cout << "ENTER LENGTH: ";
    cin >> len;

    substring(s, ip, len, dest);

    cout << "SUBSTRING = " << dest << endl;

    return 0;
}