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

//find minimum index then swap with i
void SelectionSort(int *a, int n)
{
    // 0 1 2  3 4
    // 3 5 2 13 12

    int IndexOfMin;
    for (int i = 0; i < n - 1; i++) // no of passes
    {
        IndexOfMin = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[IndexOfMin])
            {
               IndexOfMin=j;
            }
        }

        int temp;
        temp=a[i];
        a[i]=a[IndexOfMin];
        a[IndexOfMin]=temp;
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

    SelectionSort(arr, n);

    display(arr, n);

    return 0;
}