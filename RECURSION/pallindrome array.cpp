#include <iostream>
using namespace std;

bool palindrome(int *l, int *r)
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

void input(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "ENTER ELEMENT " << i + 1 << ": ";
        cin >> a[i];
    }
}

int main()
{
    int n;

    cout << "ENTER SIZE OF ARRAY: ";
    cin >> n;

    int arr[n];

    input(arr, n);

    if(palindrome(&arr[0], &arr[n-1]))
    {
        cout << "ARRAY IS PALINDROME" << endl;
    }
    else
    {
        cout << "ARRAY IS NOT PALINDROME" << endl;
    }

    return 0;
}