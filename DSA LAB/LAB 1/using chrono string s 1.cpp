#include <iostream>
#include <chrono>
using namespace std;

int main()
{
    string s;
    cout << "ENTER A STRING: ";
    getline(cin, s);

    // Manual method
    auto start1 = chrono::high_resolution_clock::now();

    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }

    auto end1 = chrono::high_resolution_clock::now();

    // s.length() method
    auto start2 = chrono::high_resolution_clock::now();

    int length = s.length();

    auto end2 = chrono::high_resolution_clock::now();

    auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);
    auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);

    cout << "Manual length: " << len << endl;
    cout << "Manual method time: " << duration1.count() << " microseconds" << endl;

    cout << "s.length(): " << length << endl;
    cout << "s.length() time: " << duration2.count() << " microseconds" << endl;

    return 0;
}