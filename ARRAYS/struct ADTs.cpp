#include <iostream>
using namespace std;

struct myArray
{
    int total_size;
    int used_size;
    int *arr;
};

// CREATE ARRAY
void createArray(myArray *a, int tSize, int uSize)
{
    a->total_size = tSize;
    a->used_size = uSize;
    a->arr = new int[tSize];
}

// SET VALUES
void setVAL(myArray *a)
{
    int n;

    for (int i = 0; i < a->used_size; i++)
    {
        cout << "ENTER ELEMENT " << i << ":";
        cin >> n;
        a->arr[i] = n;
    }
}

// DISPLAY ARRAY
void display(myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        cout << "ELEMENT" << i << ":" << a->arr[i] << endl;
    }
}

// INSERTION
int insertion(myArray *a, int element, int index)
{
    if (a->used_size >= a->total_size)
    {
        cout << "OUT OF RANGE!" << endl;
        return 0;
    }

    if (index < 0 || index > a->used_size)
    {
        cout << "LOGICAL ERROR!" << endl;
        return 0;
    }

    for (int i = a->used_size - 1; i >= index; i--)
    {
        a->arr[i + 1] = a->arr[i];
    }

    a->arr[index] = element;

    cout << "THE ELEMENT " << element
         << " IS INSERTED AT "
         << index << " INDEX!" << endl;

    return 1;
}

// DELETION
int deletion(myArray *a, int element)
{
    if (a->used_size <= 0)
    {
        cout << "ARRAY IS EMPTY!" << endl;
        return 0;
    }

    bool present = false;
    int position;

    for (int i = 0; i < a->used_size; i++)
    {
        if (a->arr[i] == element)
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
        for (int i = position; i < a->used_size - 1; i++)
        {
            a->arr[i] = a->arr[i + 1];
        }
    }

    cout << "THE ELEMENT " << element
         << " IS DELETED AT "
         << position << " INDEX!" << endl;

    return 1;
}

// LINEAR SEARCH
bool linearSearch(myArray *a, int element)
{
    bool present = false;

    for (int i = 0; i < a->used_size; i++)
    {
        if (a->arr[i] == element)
        {
            present = true;
            break;
        }
    }

    if (present)
    {
        cout << "ELEMENT FOUND!" << endl;
        return true;
    }

    else
    {
        cout << "ELEMENT NOT FOUND!" << endl;
        return false;
    }
}

// BINARY SEARCH
bool binarySearch(myArray *a, int element)
{
    int mid, high, low;

    low = 0;
    high = a->used_size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a->arr[mid] == element)
        {
            cout << "ELEMENT FOUND AT INDEX: " << mid << endl;
            return true;
        }

        if (a->arr[mid] < element)
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
    myArray A1;

    createArray(&A1, 100, 5);

    setVAL(&A1);

    cout << endl
         << "ARRAY ELEMENTS:" << endl;
    display(&A1);

    int element;
    int index;

    cout << "ENTER THE ELEMENT YOU WANT TO INSERT:";
    cin >> element;

    cout << "ENTER THE INDEX:";
    cin >> index;

    if (insertion(&A1, element, index))
    {
        A1.used_size += 1;
    }

    cout << endl
         << "AFTER INSERTION:" << endl;
    display(&A1);

    cout << "ENTER THE ELEMENT YOU WANT TO DELETE:";
    cin >> element;

    if (deletion(&A1, element))
    {
        A1.used_size -= 1;
    }

    cout << endl
         << "AFTER DELETION:" << endl;
    display(&A1);

    cout << "ENTER ELEMENT TO SEARCH:";
    cin >> element;

    linearSearch(&A1, element);

    delete[] A1.arr;

    return 0;
}