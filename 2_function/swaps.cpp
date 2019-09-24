#include <iostream>

void swapr(int &a, int & b);
void swappp(int * a, int * b);
void swapv(int a, int b);


int main()
{
    using namespace std;
    int wallet1 = 300;
    int wallet2 = 350;
    cout << "wallet1 = $ "<<wallet1<<endl;
    cout << "wallet2 = $ "<<wallet2<<endl;

    cout << "Using references to swap contents:"<<endl;
    swapr(wallet1, wallet2);
    cout << "wallet1 = $ "<<wallet1<<endl;
    cout << "wallet2 = $ "<<wallet2<<endl;

    cout << "Using pointera to swap contents:"<<endl;
    swappp(&wallet1, &wallet2);
    cout << "wallet1 = $ "<<wallet1<<endl;
    cout << "wallet2 = $ "<<wallet2<<endl;

    cout << "Trying to use passing by values:"<<endl;
    swapv(wallet1, wallet2);
    cout << "wallet1 = $ "<<wallet1<<endl;
    cout << "wallet2 = $ "<<wallet2<<endl;
    
    return 0;
}

void swapr(int & a, int & b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swappp(int * a, int * b)
{
    int temp;

    temp = * a;
    *a = *b;
    *b = temp;
}

void swapv(int a, int b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}
