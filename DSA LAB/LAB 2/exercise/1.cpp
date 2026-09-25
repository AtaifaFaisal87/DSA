#include <iostream>
using namespace std;

// LAB 1: LENGTH
int myLength(const char s[])
{
    int len = 0;

    while (s[len] != '\0')
        len++;

    return len;
}

// LAB 1: CONCATENATE
void myConcatenate(char s1[], const char s2[])
{
    int i = myLength(s1);
    int j = myLength(s2);
    int count = 0;

    while (count <= j)
    {
        s1[i] = s2[count];
        i++;
        count++;
    }
}

// LAB 1: SUBSTRING
void mySubstring(const char s[], int ip, int len, char dest[])
{
    int i = ip;
    int count = 0;

    while (count < len && s[i] != '\0')
    {
        dest[count] = s[i];
        count++;
        i++;
    }

    dest[count] = '\0';
}

// ALGORITHM A1: INSERT
void A1(char T[], int ip, char P[])
{
    char temp1[200];
    char temp2[200];

    mySubstring(T, 0, ip, temp1);

    mySubstring(T, ip, myLength(T) - ip + 1, temp2);

    myConcatenate(temp1, P);

    myConcatenate(temp1, temp2);

    int i = 0;

    while (temp1[i] != '\0')
    {
        T[i] = temp1[i];
        i++;
    }

    T[i] = '\0';
}

// ALGORITHM A2: DELETE
void A2(char T[], int ip, int L)
{
    char temp1[200];
    char temp2[200];

    mySubstring(T, 0, ip, temp1);

    mySubstring(T, ip + L, myLength(T) - ip - L + 1, temp2);

    myConcatenate(temp1, temp2);

    int i = 0;

    while (temp1[i] != '\0')
    {
        T[i] = temp1[i];
        i++;
    }

    T[i] = '\0';
}

int main()
{
    char T1[200] = "The founder of our country was Quaid-e-Azam";
    char P[200] = "and first Governor General";

    char T2[200] = "Database Management Systems";

    // A1
    A1(T1, 12, P);

    cout << "A1 Result: " << T1 << endl;

    // A2
    A2(T2, 9, 10);

    cout << "A2 Result: " << T2 << endl;

    return 0;
}