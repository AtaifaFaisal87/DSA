#include <iostream>
using namespace std;

// A1: Length
int myLength(const char s[])
{
    int len = 0;

    while (s[len] != '\0')
    {
        len++;
    }

    return len;
}

// A2: Concatenate
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

// A3: Substring
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

// A4: Index / Search
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
            {
                break;
            }
        }

        if (j == p)
        {
            return i;
        }

        i++;
    }

    return -1;
}

int main()
{
    char s[200];
    char s1[200];
    char s2[200];
    char dest[200];
    char T[200];
    char P[200];

    int choice;

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. LENGTH" << endl;
        cout << "2. CONCATENATE" << endl;
        cout << "3. SUB-STRING" << endl;
        cout << "4. INDEX / SEARCH" << endl;
        cout << "5. EXIT" << endl;
        cout << "==========================\n";

        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            cout << "\nENTER STRING: ";
            cin.getline(s, 200);

            cout << "LENGTH = " << myLength(s) << endl;

            break;
        }

        case 2:
        {
            cout << "\nENTER FIRST STRING: ";
            cin.getline(s1, 200);

            cout << "ENTER SECOND STRING: ";
            cin.getline(s2, 200);

            myConcatenate(s1, s2);

            cout << "CONCATENATED STRING = " << s1 << endl;

            break;
        }

        case 3:
        {
            int ip;
            int len;

            cout << "\nENTER STRING: ";
            cin.getline(s, 200);

            cout << "ENTER STARTING POSITION: ";
            cin >> ip;

            cout << "ENTER LENGTH: ";
            cin >> len;
            cin.ignore();

            mySubstring(s, ip, len, dest);

            cout << "SUBSTRING = " << dest << endl;

            break;
        }

        case 4:
        {
            cout << "\nENTER TEXT (T): ";
            cin.getline(T, 200);

            cout << "ENTER PATTERN (P): ";
            cin.getline(P, 200);

            cout << "INDEX = " << myIndex(T, P) << endl;

            break;
        }

        case 5:
        {
            cout << "\nPROGRAM ENDED!" << endl;

            break;
        }

        default:
        {
            cout << "\nINVALID CHOICE!" << endl;
        }
        }

    } while (choice != 5);

    return 0;
}