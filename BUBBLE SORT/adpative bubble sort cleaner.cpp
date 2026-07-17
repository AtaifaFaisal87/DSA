#include <iostream>
using namespace std;

void input(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "ENTER ELEMENT " << i << ":";
        cin >> a[i];
    }
}

void display(int *a, int n)
{
    cout << "=======PRINTING ELEMENTS=======" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "ELEMENT " << i << ":" << a[i] << endl;
    }
}

void BubbleSort(int *a, int n)
{
    bool isSorted = false;

    for (int i = 0; i < n - 1; i++) // no of passes
    {
        isSorted = true;

        for (int j = 0; j < n - 1 - i; j++) // no of comparisions
        {
            if (a[j] > a[j + 1])
            {
                int temp;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                isSorted = false;
            }
        }

        if (isSorted)
        {
            cout << "THE ARRAY SORTED AT PASS NUMBER: " << i << endl;
            return;
        }
    }
}

int main()
{
    int n;
    cout << "ENTER THE SIZE OF ARRAY:";
    cin >> n;

    int arr[n];

    input(arr, n);
    display(arr, n);

    BubbleSort(arr, n);

    return 0;
}