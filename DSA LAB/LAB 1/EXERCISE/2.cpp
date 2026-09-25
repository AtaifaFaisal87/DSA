#include <iostream>
#include <cstring>
#include <string>
#include <chrono>

using namespace std;

// A1: LENGTH
int myLength(const char s[])
{
    int len = 0;

    while (s[len] != '\0')
    {
        len++;
    }

    return len;
}

// A2: CONCATENATE
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

// A3: SUBSTRING
void mySubstring(const char s[], int ip, int len, char dest[])
{
    int i = ip;
    int count = 0;

    while (count < len)
    {
        dest[count] = s[i];
        count++;
        i++;
    }

    dest[count] = '\0';
}

// A4: INDEX / SEARCH
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
    const int repetitions = 1000000;

    // A1
    const char s[] = "A computer is an idiot machine";

    int manualLengthResult = 0;
    int builtInLengthResult = 0;

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < repetitions; i++)
    {
        manualLengthResult = myLength(s);
    }

    auto end = chrono::high_resolution_clock::now();

    auto manualLengthTime =
        chrono::duration_cast<chrono::microseconds>(end - start).count();

    start = chrono::high_resolution_clock::now();

    for (int i = 0; i < repetitions; i++)
    {
        builtInLengthResult = strlen(s);
    }

    end = chrono::high_resolution_clock::now();

    auto builtInLengthTime =
        chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "\n========== A1: LENGTH ==========\n";
    cout << "STRING: " << s << endl;
    cout << "MANUAL LENGTH = " << manualLengthResult << endl;
    cout << "MANUAL TIME = " << manualLengthTime << " MICROSECONDS" << endl;
    cout << "STRLEN() LENGTH = " << builtInLengthResult << endl;
    cout << "STRLEN() TIME = " << builtInLengthTime << " MICROSECONDS" << endl;

    // A2
    const char originalS1[] = "But";
    const char s2[] = "ter";

    char manualS1[100];
    char builtInS1[100];

    start = chrono::high_resolution_clock::now();

    for (int i = 0; i < repetitions; i++)
    {
        strcpy(manualS1, originalS1);
        myConcatenate(manualS1, s2);
    }

    end = chrono::high_resolution_clock::now();

    auto manualConcatTime =
        chrono::duration_cast<chrono::microseconds>(end - start).count();

    start = chrono::high_resolution_clock::now();

    for (int i = 0; i < repetitions; i++)
    {
        strcpy(builtInS1, originalS1);
        strcat(builtInS1, s2);
    }

    end = chrono::high_resolution_clock::now();

    auto builtInConcatTime =
        chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "\n========== A2: CONCATENATE ==========\n";
    cout << "S1: " << originalS1 << endl;
    cout << "S2: " << s2 << endl;
    cout << "MANUAL RESULT = " << manualS1 << endl;
    cout << "MANUAL TIME = " << manualConcatTime << " MICROSECONDS" << endl;
    cout << "STRCAT() RESULT = " << builtInS1 << endl;
    cout << "STRCAT() TIME = " << builtInConcatTime << " MICROSECONDS" << endl;

    // A3
    const char subString[] =
        "Unix is a multi-user operating system";

    int ip = 24;
    int len = 6;

    char manualDest[100];

    string standardString = subString;
    string builtInDest;

    start = chrono::high_resolution_clock::now();

    for (int i = 0; i < repetitions; i++)
    {
        mySubstring(subString, ip, len, manualDest);
    }

    end = chrono::high_resolution_clock::now();

    auto manualSubstringTime =
        chrono::duration_cast<chrono::microseconds>(end - start).count();

    start = chrono::high_resolution_clock::now();

    for (int i = 0; i < repetitions; i++)
    {
        builtInDest = standardString.substr(ip, len);
    }

    end = chrono::high_resolution_clock::now();

    auto builtInSubstringTime =
        chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "\n========== A3: SUBSTRING ==========\n";
    cout << "STRING: " << subString << endl;
    cout << "STARTING POSITION = " << ip << endl;
    cout << "LENGTH = " << len << endl;
    cout << "MANUAL RESULT = " << manualDest << endl;
    cout << "MANUAL TIME = " << manualSubstringTime
         << " MICROSECONDS" << endl;
    cout << "SUBSTR() RESULT = " << builtInDest << endl;
    cout << "SUBSTR() TIME = " << builtInSubstringTime
         << " MICROSECONDS" << endl;

    // A4
    const char T[] = "clearly";
    const char P[] = "early";

    int manualIndexResult = 0;
    size_t builtInIndexResult = 0;

    string text = T;
    string pattern = P;

    start = chrono::high_resolution_clock::now();

    for (int i = 0; i < repetitions; i++)
    {
        manualIndexResult = myIndex(T, P);
    }

    end = chrono::high_resolution_clock::now();

    auto manualIndexTime =
        chrono::duration_cast<chrono::microseconds>(end - start).count();

    start = chrono::high_resolution_clock::now();

    for (int i = 0; i < repetitions; i++)
    {
        builtInIndexResult = text.find(pattern);
    }

    end = chrono::high_resolution_clock::now();

    auto builtInIndexTime =
        chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "\n========== A4: INDEX / SEARCH ==========\n";
    cout << "T = " << T << endl;
    cout << "P = " << P << endl;
    cout << "MANUAL INDEX = " << manualIndexResult << endl;
    cout << "MANUAL TIME = " << manualIndexTime
         << " MICROSECONDS" << endl;
    cout << "FIND() INDEX = " << builtInIndexResult << endl;
    cout << "FIND() TIME = " << builtInIndexTime
         << " MICROSECONDS" << endl;

    cout << "\n========================================\n";
    cout << "             COMPARISON DONE\n";
    cout << "========================================\n";

    return 0;
}