#include <iostream>
using namespace std;

void display(int *a, int n)
{
    cout << "=======PRINTING ELEMENTS=======" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "ELEMENT " << i << ":" << a[i] << endl;
    }
}

void merge(int low, int high, int mid, int a[], int size)
{

    // 0  1 2 3 4
    // 7,15,2,8,10

    int b[size];
    int i = low;
    int k = low;
    int j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }

    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

int main()
{
    int arr[5] = {7, 15, 2, 8, 10};
    int low = 0;
    int high = 4;
    int mid = 1;
    int size = 5;

    merge(low, high, mid, arr, size);
    display(arr, size);
}