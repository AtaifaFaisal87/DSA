#include <iostream>
#include <cstring>
using namespace std;

char* substring(char T[], int start, int length)
{
    char* temp = new char[length + 1];

    for (int i = 0; i < length; i++)
        temp[i] = T[start + i];

    temp[length] = '\0';

    return temp;
}

char* concatenate(char A[], char B[])
{
    int len1 = strlen(A);
    int len2 = strlen(B);

    char* temp = new char[len1 + len2 + 1];

    for (int i = 0; i < len1; i++)
        temp[i] = A[i];

    for (int i = 0; i < len2; i++)
        temp[len1 + i] = B[i];

    temp[len1 + len2] = '\0';

    return temp;
}

int main()
{
    char T[100], P[100];
    char *temp1, *temp2;
    int ip;

    cout << "Enter T: ";
    cin >> T;

    cout << "Enter P: ";
    cin >> P;

    cout << "Enter ip: ";
    cin >> ip;

    // A1: ins(T, ip, P)

    temp1 = substring(T, 0, ip);

    temp2 = substring(T, ip, strlen(T) - ip);

    temp1 = concatenate(temp1, P);

    temp1 = concatenate(temp1, temp2);

    strcpy(T, temp1);

    cout << "T = " << T;

    return 0;
}