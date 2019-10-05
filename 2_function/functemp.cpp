#include <iostream>

template <typename T>
void Swap(T &a, T &b);

int main()
{
    using namespace std;
    
    int i=10;
    int j=20;
    cout << "i,j = "<<i<< ", "<<j<<".\n";
    Swap(i, j);
    cout << "Using compiler-generated double swapper:\n";
    cout << "Now i, j = "<<i<<", "<<j<<endl;

    double x =24.5;
    double y = 81.7;
    cout << "x,y = "<<x<< ", "<<y<<".\n";
    cout << "Using compiler-generated double swapper:\n";
    Swap(x,y);
    cout << "Now x, y = "<<x<<", "<<y<<endl;
    
    return 0;
}

template <typename T>
void Swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}
