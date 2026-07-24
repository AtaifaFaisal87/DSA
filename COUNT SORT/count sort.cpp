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

int maximum(int *a, int n)
{
    int max = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    return max;
}

void countSort(int *a, int size)
{
    int max = maximum(a, size);

    int *temp = new int[max + 1];

    for (int i = 0; i < max + 1; i++)
    {
        temp[i] = 0;
    }

    int value;

    for (int j = 0; j < size; j++)
    {
        value = a[j];
        temp[value] += 1;
    }

    int x = 0, y = 0;

    while (x <= max)
    {
        if (temp[x] != 0)
        {
            a[y] = x;
            temp[x]--;
            y++;
        }
        else
        {
            x++;
        }
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

    countSort(arr,n);
    
    display(arr, n);

    return 0;
}