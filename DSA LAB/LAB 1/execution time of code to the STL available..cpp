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

    // The execution time is very small because the string contains only 937 characters, so the operation completes within less than 1 millisecond.
    for (int i = 0; i < 1000000; i++)
    {
        len = 0;

        while (s[len] != '\0')
        {
            len++;
        }
    }

    auto end1 = chrono::high_resolution_clock::now();

    // s.length() method
    auto start2 = chrono::high_resolution_clock::now();

    int length = 0;

    for (int i = 0; i < 1000000; i++)
    {
        length = s.length();
    }

    auto end2 = chrono::high_resolution_clock::now();

    // Calculate time
    auto duration1 =
        chrono::duration_cast<chrono::milliseconds>(end1 - start1);

    auto duration2 =
        chrono::duration_cast<chrono::milliseconds>(end2 - start2);

    cout << "\nManual length: " << len << endl;
    cout << "Manual method time: "
         << duration1.count() << " milliseconds" << endl;

    cout << "\ns.length(): " << length << endl;
    cout << "s.length() time: "
         << duration2.count() << " milliseconds" << endl;

    return 0;
}

// input
/*
Artificial intelligence has become an important part of modern technology, influencing education,
healthcare, business, communication, transportation, and many other fields. Computers are now capable
of processing large amounts of information quickly and performing tasks that previously required significant
human effort. In education, technology helps students access learning materials, practice programming, solve mathematical
problems, and communicate with teachers and classmates. As technology continues to develop, understanding how computer programs
work and how efficiently they process data is becoming increasingly important for students and professionals. Algorithms play a
major role in determining how quickly a program can perform a particular task, especially when the amount of data becomes very
large. Therefore, programmers often compare different approaches to determine which method requires less time and fewer resources.
*/