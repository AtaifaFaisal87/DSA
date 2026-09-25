#include <iostream>
#include <string>
#include <chrono>

using namespace std;

int main()
{
    string str1;
    string str2;

    cout << "ENTER FIRST STRING: ";
    getline(cin, str1);

    cout << "ENTER SECOND STRING: ";
    getline(cin, str2);

    // MANUAL
    auto start1 = chrono::high_resolution_clock::now();

    for (int k = 0; k < 1000000; k++)
    {
        string manual = str1;

        int size = manual.length();
        manual.resize(size + str2.length());

        int i = 0;

        while (str2[i] != '\0')
        {
            manual[size + i] = str2[i];
            i++;
        }
    }

    auto end1 = chrono::high_resolution_clock::now();

    // BUILT-IN
    auto start2 = chrono::high_resolution_clock::now();

    for (int k = 0; k < 1000000; k++)
    {
        string builtIn = str1 + str2;
    }

    auto end2 = chrono::high_resolution_clock::now();

    auto duration1 =
        chrono::duration_cast<chrono::milliseconds>(end1 - start1);

    auto duration2 =
        chrono::duration_cast<chrono::milliseconds>(end2 - start2);

    cout << "\nMANUAL METHOD TIME: "
         << duration1.count() << " milliseconds" << endl;

    cout << "BUILT-IN METHOD TIME: "
         << duration2.count() << " milliseconds" << endl;

    return 0;
}