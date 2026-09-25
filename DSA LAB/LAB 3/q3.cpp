#include <iostream>
using namespace std;

class Matrix
{
private:
    int rows;
    int cols;
    int **Arr;

public:

    Matrix(int r, int c)
    {
        rows = r;
        cols = c;

        Arr = new int *[rows];

        for (int i = 0; i < rows; i++)
        {
            Arr[i] = new int[cols];
        }
    }

    Matrix(const Matrix &M)
    {
        rows = M.rows;
        cols = M.cols;

        Arr = new int *[rows];

        for (int i = 0; i < rows; i++)
        {
            Arr[i] = new int[cols];

            for (int j = 0; j < cols; j++)
            {
                Arr[i][j] = M.Arr[i][j];
            }
        }
    }


    void input()
    {
        cout << "INPUT ELEMENTS OF MATRIX:" << endl;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << "ENTER ELEMENT [" << i << "][" << j << "] : ";
                cin >> Arr[i][j];
            }
        }
    }


    void display()
    {
        cout << "ELEMENTS OF MATRIX:" << endl;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << Arr[i][j] << " ";
            }

            cout << endl;
        }
    }


    Matrix operator*(const Matrix &B)
    {
        if (cols != B.rows)
        {
            cout << "ERROR: Matrix multiplication is not possible!" << endl;
            return Matrix(0, 0);
        }

        Matrix C(rows, B.cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < B.cols; j++)
            {
                C.Arr[i][j] = 0;

                for (int k = 0; k < cols; k++)
                {
                    C.Arr[i][j] =
                        C.Arr[i][j] + Arr[i][k] * B.Arr[k][j];
                }
            }
        }

        return C;
    }


    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] Arr[i];
        }

        delete[] Arr;
    }
};


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

    Matrix A(rA, cA);
    Matrix B(rB, cB);

    cout << "ENTER MATRIX A:" << endl;
    A.input();

    cout << "ENTER MATRIX B:" << endl;
    B.input();

    Matrix C = A * B;

    cout << "PRODUCT MATRIX:" << endl;
    C.display();

    return 0;
}