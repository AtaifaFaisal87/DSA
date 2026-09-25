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

void repeatString(const char S[], int n, char result[])
{
    int i = 0;
    int length = myLength(S);

    while (i < n)
    {
        int j = 0;

        while (j < length)
        {
            result[i] = S[j];
            i++;
            j++;

            if (i >= n)
            {
                break;
            }
        }
    }

    result[i] = '\0';
}

int main()
{
    char S[100];
    char result[100];
    int n;

    cout << "ENTER STRING: ";
    cin.getline(S, 100);

    cout << "ENTER N: ";
    cin >> n;

    repeatString(S, n, result);

    cout << "RESULT = " << result << endl;

    return 0;
}