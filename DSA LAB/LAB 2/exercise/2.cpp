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

// LAB 1: INDEX
int myIndex(const char T[], const char P[])
{
    int t = myLength(T);
    int p = myLength(P);

    int i = 0;
    int max = t - p + 1;

    while (i < max)
    {
        int j;

        for (j = 0; j < p; j++)
        {
            if (P[j] != T[i + j])
                break;
        }

        if (j == p)
            return i;

        i++;
    }

    return -1;
}

// ALGORITHM A2: DELETE
void A2(char T[], int ip, int L)
{
    char temp1[200];
    char temp2[200];

    mySubstring(T, 0, ip, temp1);

    mySubstring(T, ip + L,
                myLength(T) - ip - L + 1,
                temp2);

    myConcatenate(temp1, temp2);

    int i = 0;

    while (temp1[i] != '\0')
    {
        T[i] = temp1[i];
        i++;
    }

    T[i] = '\0';
}

// Q2: DELETE EVERY OCCURRENCE
void deleteAll(char T[], char P[])
{
    int ip;

    ip = myIndex(T, P);

    while (ip != -1)
    {
        A2(T, ip, myLength(P));

        ip = myIndex(T, P);
    }
}

int main()
{
    char T[200] = "abcXXabcYYabc";
    char P[100] = "abc";

    deleteAll(T, P);

    cout << "Original T: abcXXabcYYabc" << endl;
    cout << "Pattern P: " << P << endl;
    cout << "After deletion: " << T << endl;

    return 0;
}