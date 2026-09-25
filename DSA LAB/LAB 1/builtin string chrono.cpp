#include <iostream>
#include <chrono>
using namespace std;

int main()
{
    auto start = chrono::high_resolution_clock::now();

    string s;
    cout << "ENTER A STRING:";
    getline(cin, s);

    cout << "THE LENGTH OF YOUR STRING IS:" << s.length()<<endl;

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::seconds>(end - start);

    cout << "Execution time: " << duration.count() << " seconds";

    return 0;
}