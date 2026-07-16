#include <iostream>
using namespace std;

void display(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}

void reverse(int *l, int *r, int *a)
{
    if (l >= r)
    {
        display(a,6);
        return;
    }

    int temp = *l;
    *l = *r;
    *r = temp;

    reverse(l+1,r-1,a);
}

int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
     int* left=&arr[0];
     int* right=&arr[5];
 
     reverse(left,right,arr);
}