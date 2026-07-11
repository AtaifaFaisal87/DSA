#include <iostream>
using namespace std;

void display(int *a, int uSize)
{
    for (int i = 0; i < uSize; i++)
    {
        cout << "ELEMENT" << i << ":" << a[i]<<endl;
    }
}

int insertion(int *a, int capacity, int uSize, int element, int index)
{
    if (uSize >= capacity)
    {
        cout << "OUT OF RANGE!" << endl;
        return 0;
    }

    if (index < 0 || index > uSize)
    {
        cout << "LOGICAL ERROR!" << endl;
        return 0;
    }

    for (int i = uSize - 1; i >= index; i--)
    {
        a[i + 1] = a[i];
    }

    a[index] = element;
    cout << "THE ELEMENT " << element << " IS INSERTED AT " << index << " INDEX!" << endl;
    return 1;
}

int main()
{
    int arr[50] = {4, 6, 1, 10};
    int capacity = 50;
    int used = 4;

    int element;
    cout << "ENTER THE ELEMENT YOU WANT TO ENTER:";
    cin >> element;

    int index;
    cout << "ENTER THE INDEX (0-4):";
    cin >> index;

    if (insertion(arr, capacity, used, element, index))
    {
        used += 1;
    }

    display(arr, used);

    return 0;
}