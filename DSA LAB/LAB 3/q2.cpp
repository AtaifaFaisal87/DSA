#include <iostream>
using namespace std;

void input(int **Arr, int r, int c)
{
    cout << "INPUT ELEMENTS OF MATRIX:" << endl;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "ENTER ELEMENT [" << i << "][" << j << "] : ";
            cin >> Arr[i][j];
        }
    }
}

bool matMUL(int **A, int **B, int **C,
            int rA, int cA, int rB, int cB)
{

    if (cA != rB)
    {
        cout << "ERROR: Matrix multiplication is not possible." << endl;
        cout << "Columns of A must be equal to rows of B." << endl;
        return false;
    }

    for (int i = 0; i < rA; i++)
    {
        for (int j = 0; j < cB; j++)
        {
            C[i][j] = 0;

            for (int k = 0; k < cA; k++)
            {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    return true;
}

void display(int **Arr, int r, int c)
{
    cout << "RESULT MATRIX:" << endl;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << Arr[i][j] << " ";
        }

        cout << endl;
    }
}

int main()
{
    int rA, cA, rB, cB;

    cout << "ENTER ROWS OF MATRIX A: ";
    cin >> rA;

    cout << "ENTER COLUMNS OF MATRIX A: ";
    cin >> cA;

    cout << "ENTER ROWS OF MATRIX B: ";
    cin >> rB;

    cout << "ENTER COLUMNS OF MATRIX B: ";
    cin >> cB;

    int **A = new int *[rA];

    for (int i = 0; i < rA; i++)
    {
        A[i] = new int[cA];
    }

    int **B = new int *[rB];

    for (int i = 0; i < rB; i++)
    {
        B[i] = new int[cB];
    }

    int **C = new int *[rA];

    for (int i = 0; i < rA; i++)
    {
        C[i] = new int[cB];
    }

    input(A, rA, cA);
    input(B, rB, cB);

    if (matMUL(A, B, C, rA, cA, rB, cB))
    {
        display(C, rA, cB);
    }

    for (int i = 0; i < rA; i++)
    {
        delete[] A[i];
    }
    delete[] A;

    for (int i = 0; i < rB; i++)
    {
        delete[] B[i];
    }
    delete[] B;

    for (int i = 0; i < rA; i++)
    {
        delete[] C[i];
    }
    delete[] C;

    return 0;
}