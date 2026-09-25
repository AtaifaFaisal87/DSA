#include <iostream>
using namespace std;

void input(int **Arr, int n)
{
    cout << "INPUT ELEMENTS OF MATRIX:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "ENTER ELEMENT [" << i << "][" << j << "] : ";
            cin >> Arr[i][j];
        }
    }
}

void matMUL(int **A, int **B, int **C, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;

            for (int k = 0; k < n; k++)
            {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
}

void display(int **Arr, int n)
{
    cout << "ELEMENTS OF MATRIX:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << Arr[i][j] << " ";
        }

        cout << endl;
    }
}

int main()
{
    int n;

    cout << "ENTER ORDER OF MATRICES: ";
    cin >> n;

    int **A = new int*[n];
    int **B = new int*[n];
    int **C = new int*[n];

    for (int i = 0; i < n; i++)
    {
        A[i] = new int[n];
        B[i] = new int[n];
        C[i] = new int[n];
    }

    input(A, n);
    input(B, n);

    matMUL(A, B, C, n);

    display(C, n);

    for (int i = 0; i < n; i++)
    {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}