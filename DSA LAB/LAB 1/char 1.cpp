#include<iostream>
using namespace std;

int main()
{
    char s[100];
    cout<<"ENTER A STRING:";
    cin.getline(s,100);

    int len=0;
    while( s[len] != '\0')
    {
        len++;
    }

    cout<<"THE LENGTH OF YOUR STRING IS:"<<len;

    return 0;
}