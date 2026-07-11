// Best Case:  O(n)
// Worst Case: O(n)
// Average:    O(n)

#include <iostream>
using namespace std;

int main()
{
    int arr[100] = {2, 7, 3, 2, 7, 9, 2, 10};
    int capacity = 100;
    int uSize = 8;

    int element;
    cout << "ENTER THE ELEMENT YOU WANT TO FIND:";
    cin >> element;

    bool present = false;
    int count = 0;
    for (int i = 0; i < uSize; i++)
    {
        if (arr[i] == element)
        {
            present = true;
            count++;  //bcz of this traversal throught entire array
        }
    }

    if (present)
    {
        cout << "ELEMENT FOUND....IT APPEARS IN ARRAY " << count << " TIMES" << endl;
    }

    else
    {
        cout << "ELEMENT NOT FOUND" << endl;
    }

    return 0;
}