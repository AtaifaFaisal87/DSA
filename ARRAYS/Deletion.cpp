#include <iostream>
using namespace std;

void display(int *a, int uSize)
{
    for (int i = 0; i < uSize; i++)
    {
        cout << "ELEMENT" << i << ":" << a[i] << endl;
    }
}

int deletion(int *a, int capacity, int uSize, int element)
{

    if (uSize <= 0)
    {
        cout << "ARRAY IS EMPTY1";
        return 0;
    }

    bool present = false;
    int position;
    for (int i = 0; i < uSize; i++)
    {
        if (a[i] == element)
        {
            present = true;
            position = i;
            break;
        }
    }

    if (!present)
    {
        cout << "ELEMENT NOT FOUND!" << endl;
        return 0;
    }

    if (present)
    {
        for (int i = position; i < uSize - 1; i++)
        {
            a[i] = a[i + 1];
        }
    }

    cout << "THE ELEMENT" << element << "IS DELETED AT" << position << "INDEX!" << endl;
    return 1;
}

int main()
{
    int arr[50] = {4, 6, 1, 10};
    int capacity = 50;
    int used = 4;

    int element;
    cout << "ENTER THE ELEMENT YOU WANT TO DELETE:";
    cin >> element;

    if (deletion(arr, capacity, used, element))
    {
        used -= 1;
    }

    display(arr, used);

    return 0;
}