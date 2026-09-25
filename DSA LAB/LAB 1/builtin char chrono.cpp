#include <iostream>
#include <chrono>
#include<cstring>

using namespace std;

int main()
{
    auto start = chrono::high_resolution_clock::now();

    char s[100];
    cout << "ENTER A STRING:";
    cin.getline(s, 100);

    cout << "THE LENGTH OF YOUR STRING IS:" << strlen(s);

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::seconds>(end - start);

    cout << "Execution time: " << duration.count() << " seconds";

    return 0;
}