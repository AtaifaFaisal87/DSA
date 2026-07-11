#include <iostream>
using namespace std;

struct myArray
{
    int total_size;
    int used_size;
    int *arr;
};

void createArray(struct myArray *a, int tSize, int uSize)
{
    (*a).total_size = tSize;
    (*a).used_size=uSize;
    (*a).arr = new int(tSize);

}

void setVAL(struct myArray *a)
{
    int n;
    for(int i=0;i<a->used_size;i++)
    {
        cout<<"ENTER ELEMENT "<<i <<":";
        cin>>n;
        (a->arr)[i]=n;
    }
}

void show(struct myArray *a)
{
    for(int i=0;i<a->used_size;i++)
    {
        cout<<"VALUE:"<<(a->arr)[i];
    }
}

int main()
{
    struct myArray A1;
    createArray(&A1, 100, 200);
    setVAL(&A1);
    show(&A1);
    return 0;
}