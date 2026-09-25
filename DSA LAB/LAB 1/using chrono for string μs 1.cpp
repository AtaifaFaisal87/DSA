#include <iostream>
#include <chrono>
using namespace std;

int main()
{
    auto start = chrono::high_resolution_clock::now();

    string s;
    cout << "ENTER A STRING: ";
    getline(cin, s);

    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }

    cout << "THE LENGTH OF YOUR STRING IS: " << len << endl;

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Execution time: " << duration.count() << " microseconds";

    return 0;
}