#include <iostream>
using namespace std;

bool palindrome(char *l, char *r)
{
    if(l >= r)
    {
        return true;
    }

    if(*l != *r)
    {
        return false;
    }

    return palindrome(l + 1, r - 1);
}

int main()
{
    string str;

    cout << "ENTER STRING: ";
    cin >> str;

    if(palindrome(&str[0], &str[str.length() - 1]))
    {
        cout << "STRING IS PALINDROME" << endl;
    }
    else
    {
        cout << "STRING IS NOT PALINDROME" << endl;
    }

    return 0;
}