#include <iostream>
#include <string>
#include <chrono>

using namespace std;

int main()
{
    string s;
    int start;
    int length;

    cout << "ENTER A STRING: ";
    getline(cin, s);

    cout << "ENTER STARTING INDEX: ";
    cin >> start;

    cout << "ENTER LENGTH: ";
    cin >> length;

    // MANUAL
    auto start1 = chrono::high_resolution_clock::now();

    string manual;

    for (int k = 0; k < 1000000; k++)
    {
        manual = "";

        for (int i = start; i < start + length; i++)
        {
            manual += s[i];
        }
    }

    auto end1 = chrono::high_resolution_clock::now();

    // BUILT-IN
    auto start2 = chrono::high_resolution_clock::now();

    string builtIn;

    for (int k = 0; k < 1000000; k++)
    {
        builtIn = s.substr(start, length);
    }

    auto end2 = chrono::high_resolution_clock::now();

    auto duration1 =
        chrono::duration_cast<chrono::milliseconds>(end1 - start1);

    auto duration2 =
        chrono::duration_cast<chrono::milliseconds>(end2 - start2);

    cout << "\nMANUAL SUBSTRING: " << manual << endl;
    cout << "BUILT-IN SUBSTRING: " << builtIn << endl;

    cout << "MANUAL METHOD TIME: "
         << duration1.count() << " milliseconds" << endl;

    cout << "BUILT-IN METHOD TIME: "
         << duration2.count() << " milliseconds" << endl;

    return 0;
}