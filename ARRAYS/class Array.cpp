#include <iostream>
using namespace std;

class MyArray
{
private:
    int total_size;
    int used_size;
    int *arr;

public:
    // CONSTRUCTOR
    MyArray(int tSize, int uSize)
    {
        total_size = tSize;
        used_size = uSize;
        arr = new int[tSize];
    }

    // SET VALUES
    void setVAL()
    {
        int n;

        for (int i = 0; i < used_size; i++)
        {
            cout << "ENTER ELEMENT " << i << ":";
            cin >> n;
            arr[i] = n;
        }
    }

    // DISPLAY ARRAY
    void display()
    {
        for (int i = 0; i < used_size; i++)
        {
            cout << "ELEMENT" << i << ":" << arr[i] << endl;
        }
    }

    // INSERTION
    bool insertion(int element, int index)
    {
        if (used_size >= total_size)
        {
            cout << "OUT OF RANGE!" << endl;
            return false;
        }

        if (index < 0 || index > used_size)
        {
            cout << "LOGICAL ERROR!" << endl;
            return false;
        }

        for (int i = used_size - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }

        arr[index] = element;
        used_size++;

        cout << "THE ELEMENT " << element
             << " IS INSERTED AT "
             << index << " INDEX!" << endl;

        return true;
    }

    // DELETION
    bool deletion(int element)
    {
        if (used_size <= 0)
        {
            cout << "ARRAY IS EMPTY!" << endl;
            return false;
        }

        bool present = false;
        int position;

        for (int i = 0; i < used_size; i++)
        {
            if (arr[i] == element)
            {
                present = true;
                position = i;
                break;
            }
        }

        if (!present)
        {
            cout << "ELEMENT NOT FOUND!" << endl;
            return false;
        }

        for (int i = position; i < used_size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        used_size--;

        cout << "THE ELEMENT " << element
             << " IS DELETED AT "
             << position << " INDEX!" << endl;

        return true;
    }

    // LINEAR SEARCH
    bool linearSearch(int element)
    {
        bool present = false;

        for (int i = 0; i < used_size; i++)
        {
            if (arr[i] == element)
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
    bool binarySearch(int element)
    {
        int mid, low, high;

        low = 0;
        high = used_size - 1;

        while (low <= high)
        {
            mid = (low + high) / 2;

            if (arr[mid] == element)
            {
                cout << "ELEMENT FOUND AT INDEX:" << mid << endl;
                return true;
            }

            if (arr[mid] < element)
            {
                low = mid + 1;
            }

            else
            {
                high = mid - 1;
            }
        }

        cout << "ELEMENT NOT FOUND!" << endl;
        return false;
    }

    // DESTRUCTOR
    ~MyArray()
    {
        delete[] arr;
    }
};

int main()
{
    MyArray A1(100, 5);

    A1.setVAL();

    cout << endl
         << "ARRAY ELEMENTS:" << endl;
    A1.display();

    int element;
    int index;

    cout << "ENTER THE ELEMENT YOU WANT TO INSERT:";
    cin >> element;

    cout << "ENTER THE INDEX:";
    cin >> index;

    A1.insertion(element, index);

    cout << endl
         << "AFTER INSERTION:" << endl;
    A1.display();

    cout << "ENTER THE ELEMENT YOU WANT TO DELETE:";
    cin >> element;

    A1.deletion(element);

    cout << endl
         << "AFTER DELETION:" << endl;
    A1.display();

    cout << "ENTER ELEMENT TO SEARCH:";
    cin >> element;

    A1.linearSearch(element);

    return 0;
}