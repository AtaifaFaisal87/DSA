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

void merge(int low, int high, int mid, int a[], int size)
{
    int b[size];
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }

        k++;
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

    for (int i = low; i <=  high; i++)
    {
        a[i] = b[i];
    }
}

void mergeSort(int a[], int low, int high)
{
    int size = high + 1;
    if (low < high)
    {
        int mid = (high + low) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(low, high, mid, a, size);
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

    mergeSort(arr,0,n-1);

    display(arr, n);

    return 0;
}