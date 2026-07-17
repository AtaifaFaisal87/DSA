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

void InsertionSort(int *a, int n)
{
    int key;
    int j;

//-1   0  1  2  3  4
    // 7 12 91 77 3

        /*
        Insertion Sort:
        Best Case    : O(n)
        Average Case : O(n^2)
        Worst Case   : O(n^2)

        Space       : O(1)

        Stable      : Yes
        Adaptive    : Yes
        Recursive   : No
        In-place    : Yes
    */

    for (int i = 1; i <= n - 1; i++) // no of passes
    {
        key = a[i];
        j = i - 1;

        // loop for each pass
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j+1] =key;
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

    InsertionSort(arr, n);

    display(arr, n);

    return 0;
} 