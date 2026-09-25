#include <iostream>
#include <string>
#include <chrono>

using namespace std;

int main()
{
    string s;
    char target;

    cout << "ENTER A STRING: ";
    getline(cin, s);

    cout << "ENTER CHARACTER TO SEARCH: ";
    cin >> target;

    // MANUAL - LINEAR SEARCH
    auto start1 = chrono::high_resolution_clock::now();

    int index = -1;

    for (int k = 0; k < 1000000; k++)
    {
        index = -1;

        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == target)
            {
                index = i;
                break;
            }
        }
    }

    auto end1 = chrono::high_resolution_clock::now();

    // BUILT-IN
    auto start2 = chrono::high_resolution_clock::now();

    int builtInIndex = -1;

    for (int k = 0; k < 1000000; k++)
    {
        builtInIndex = s.find(target);
    }

    auto end2 = chrono::high_resolution_clock::now();

    auto duration1 =
        chrono::duration_cast<chrono::milliseconds>(end1 - start1);

    auto duration2 =
        chrono::duration_cast<chrono::milliseconds>(end2 - start2);

    cout << "\nMANUAL INDEX: " << index << endl;
    cout << "BUILT-IN INDEX: " << builtInIndex << endl;

    cout << "MANUAL SEARCH TIME: "
         << duration1.count() << " milliseconds" << endl;

    cout << "BUILT-IN SEARCH TIME: "
         << duration2.count() << " milliseconds" << endl;

    return 0;
}