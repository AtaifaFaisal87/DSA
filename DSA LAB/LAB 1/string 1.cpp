#include<iostream>
using namespace std;

int main()
{
    string s;
    cout<<"ENTER A STRING:";
    getline(cin,s);

    int len=0;
    while( s[len] != '\0')
    {
        len++;
    }

    cout<<"THE LENGTH OF YOUR STRING IS:"<<len;

    return 0;
}