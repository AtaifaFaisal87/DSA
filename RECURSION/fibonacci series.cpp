//fibonacci series
// 0 1 1 3 5 13 18 

#include<iostream>
using namespace std;

int fib(int n)
{

    if(n==0)
    {
        return 0;
    }

    else if(n==1)
    {
        return 1;
    }
   
    else
    {
        return (fib(n-1)+fib(n-2));
    }
    
}

int main()
{
    int n;
    cout<<"ENTER THE NUMBER OF ELEMENTS OF FIBONACCI YOU WANNA PRINT:";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<fib(i)<<" ";

    }
}

