#include <iostream>

void reference_test1();     //引用基本使用
void reference_test2();     //引用做函数参数
void reference_test2_1(int& a, int& b);

int main()
{
    std::cout << "reference example." << std::endl;
    
    reference_test1();
    reference_test2();

    return 0;
}

void reference_test1()
{
    using namespace std;
    cout << "基本使用" <<endl;

    int a = 10;
    int &b = a;     //引用必须初始化

    cout << "a = "<<a <<endl;
    cout << "b = "<<b <<endl;

    b = 100;
    cout << "a = "<<a <<endl;
    cout << "b = "<<b <<endl;
}

void reference_test2()
{
    using namespace std;
    cout << "引用传参" <<endl;
    int a = 10;
    int b =100;
    cout << "a = "<<a<<endl;
    cout << "b = "<<b<<endl;
    reference_test2_1(a,b);
    cout << "a = "<<a<<endl;
    cout << "b = "<<b<<endl;
}

void reference_test2_1(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
