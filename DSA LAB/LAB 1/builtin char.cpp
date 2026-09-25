#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char s[100];
    cout<<"ENTER A STRING:";
    cin.getline(s,100);


    cout<<"THE LENGTH OF YOUR STRING IS:"<<strlen(s);

    return 0;
}