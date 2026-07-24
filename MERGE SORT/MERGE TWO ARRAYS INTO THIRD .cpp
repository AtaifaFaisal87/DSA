#include <iostream>
using namespace std;

void display(int *a, int n)
{
    cout << "=======PRINTING ELEMENTS=======" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "ELEMENT " << i << ":" << a[i] << endl;
    }
}

void merge(int *a, int *b, int *c, int m, int n)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else if (b[j] < a[i])
        {
            c[k] = b[j];
            j++;
            k++;
        }
        else
        {
            c[k] = a[i];
            k++;
            i++;
            c[k] = b[j];
            j++;
            k++;
        }
    }

    while (i < m)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < n)
    {
        c[k] = b[j];
        j++;
        k++;
    }
}
int main()
{
    int a[4]={7,22,48,64};
    int b[3]={2,8,23};

    int aSize=4;
    int bSize=3;
    int c[aSize+bSize];

    merge(a,b,c,aSize,bSize);
    display(c,aSize+bSize);

    return 0;
}