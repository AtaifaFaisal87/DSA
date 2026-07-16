#include <iostream>
using namespace std;

void display(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}
int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};

    int *l = &arr[0];
    int *r = &arr[5];

    while (l < r)
    {
        int temp = *l;
        *l = *r;
        *r = temp;

        l++;
        r--;
    }

    display(arr, 6);
    
    return 0;
}