#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cout<<"ENTER A STRING:";
    getline(cin,s);

    cout<<"THE LENGTH OF YOUR STRING IS:"<<s.length();

    return 0;
}