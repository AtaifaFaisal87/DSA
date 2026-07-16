#include <iostream>
using namespace std;

void input(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "ENTER ELEMENT " << i + 1 << ": ";
        cin >> a[i];
    }
}

void display(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}

void reverse(int *l, int *r)
{
    if(l >= r)
    {
        return;
    }

    int temp = *l;
    *l = *r;
    *r = temp;

    reverse(l + 1, r - 1);
}

int main()
{
    int n;

    cout << "ENTER SIZE OF ARRAY: ";
    cin >> n;

    int arr[n];

    input(arr, n);

    int *left = &arr[0];
    int *right = &arr[n - 1];

    reverse(left, right);

    cout << "REVERSED ARRAY:" << endl;
    display(arr, n);

    return 0;
}