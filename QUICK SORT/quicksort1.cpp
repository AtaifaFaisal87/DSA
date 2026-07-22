#include <iostream>
#include <utility>
using namespace std;

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
        while (i <= high && a[i] <= pivot) //checks for element larger than pivot
        {
            i++;
        }

        while (j >= low && a[j] > pivot)//checks for element smaller than pivot
        {
            j--;
        }

        if (i < j) //if the larger element(i) index is less than the smaller element(j) index
        {
            swap(a[i], a[j]);
        }

    } while (i < j);

    swap(a[low], a[j]); //j is the element after pivot which is smaller than pivot
    return j;
}

void quicksort(int *a, int low, int high)
{
    int partitionIndex; // returned by partition function

    if (low < high) // base case:checks whether we are still in a valid range that needs sorting
    {

        partitionIndex = partition(a, low, high);
        quicksort(a, low, partitionIndex - 1);  // sorts left part (if more than 2 checked by if statement)
        quicksort(a, partitionIndex + 1, high); // sorts right part (if more than 2 checked by if statement)
    }
}
int main()
{
    int arr[6] = {2, 4, 8, 9, 2, 9};

    display(arr, 6);

    quicksort(arr, 0, 6 - 1);

    display(arr, 6);

    return 0;
}