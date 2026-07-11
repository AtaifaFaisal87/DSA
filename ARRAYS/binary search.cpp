#include <iostream>
using namespace std;

bool binaryserach(int *a, int element, int uSIZE)
{
    int mid, high, low;
    low = 0;
    high = uSIZE - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a[mid] == element)
        {
            cout << "ELEMENT FOUND AT INDEX: " << mid << endl;
            return true;
        }

        if (a[mid] < element)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }

    
    }

        return false;
}

int main()
{
    int arr[100] = {2, 5, 8, 9, 20, 50};
    int capacity = 100;
    int uSize = 6;

    int element;
    cout << "ENTER THE ELEMENT YOU WANT TO FIND:";
    cin >> element;

    if (!binaryserach(arr, element, uSize))
    {
        cout << "ELEMENT NOT FOUND!" << endl;
    }
    return 0;
}