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

int partition(int *a, int low, int high)
{
    int temp;
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (i <= high && a[i] <= pivot)
        {
            i++;
        }

        while (j >= low && a[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quicksort(int *a, int low, int high)
{

    int partitionIndex;

    if (low < high)
    {
        partitionIndex = partition(a, low, high);
        quicksort(a, low, partitionIndex - 1);
        quicksort(a, partitionIndex + 1, high);
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

    quicksort(arr, 0, n - 1);

    display(arr, n);

    return 0;
}