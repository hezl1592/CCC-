#include <iostream>

using namespace std;

//空对象
class Person_0{
    //C++编译器会给每一个空对象分配一个字节空间"

};

class Person_1_0{
public:
    static int m_A;
};

class Person_1_1{
public:
    int m_A;
};

class Person_2_1{
public:
    static void func() {}
};

class Person_2_2{
public:
    void func() {}
};

class Person{
public:
    int m_A;        //非静态成员变量占对象空间； 
    static int m_B; //静态成员变量不占对象空间;
    //无参结构函数
    Person()
    {
        m_A = 0;
    }
    //成员函数不占对象空间，所有函数共享一个函数实例
    //
    void func()
    {
        cout << "m_A:"<<this->m_A <<endl;
    }
    //静态成员函数也不占对象空间
    static void sfunc() {}
    
};

void test_0(){
    cout << "空对象Person0占用内存空间为：\n";
    cout << "\tsize: " << sizeof(Person_0) <<endl<<endl;
}


void test_1(){
    cout << "含有一个静态成员变量的Person_1_0占用内存空间为：\n";
    cout << "\tsize: " << sizeof(Person_1_0) <<endl;
    cout << "含有一个成员变量的Person_1_1占用内存空间为：\n";
    cout << "\tsize: " << sizeof(Person_1_1) <<endl;
    cout << "result:静态成员变量不占对象空间"<<endl<<endl;
}

void test_2(){
    cout << "含有一个静态成员函数的Person_2_1占用内存空间为：\n";
    cout << "\tsize: " << sizeof(Person_2_1) <<endl;
    cout << "含有一个成员函数的Person_2_2占用内存空间为：\n";
    cout << "\tsize: " << sizeof(Person_2_2) <<endl;
    cout << "result:成员函数不占对象空间"<<endl<<endl;
}

void test_3()
{
    cout << "Person占用内存空间为：\n";
    cout << "\tsize: "<<sizeof(Person)<<endl;
}

int main()
{
    test_0();
    test_1();
    test_2();
    test_3();
    return 0;
}

