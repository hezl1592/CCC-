#include <iostream>

using namespace std;
class Person
{
public:
    static int m_A;     //声明静态成员变量
    int m_B;
    
    static void func()
    {
        cout << "\t静态成员函数func调用."<<endl;
        m_A = 100;      //静态成员函数只能访问静态成员变量
        //m_B = 100；   //不允许
    }

private:
//    静态成员函数也可以设置访问权限
    static void func2()
    {
        cout << "静态成员函数func2调用."<<endl;
    }

};

/*类外初始化静态成员变量*/
int Person::m_A = 10;


template<typename dst_type,typename src_type>
dst_type union_cast(src_type src)
{
    union{
        src_type s;
        dst_type d;
    }u;
    u.s = src;
    return u.d;
}

void test_static_variables()
{
    cout << "静态成员变量(static)：" << endl;
    cout << "1.所有对象共享同一份数据;\n";
    cout << "2.类内声明，类外进行初始化;\n";
    cout << "3.在编译阶段分配内存.\n";
    cout << "Person::m_A = " << Person::m_A << ", 地址:" <<&Person::m_A <<endl;
    Person p1;
    cout << "p1.m_A = " << p1.m_A << ", 地址:" <<&p1.m_A<<endl;
    p1.m_A = 100;
    cout << "p1.m_A = " << p1.m_A << ", 地址:" <<&p1.m_A<<endl;

    Person p2;
    p2.m_A = 200;
    cout << "p1.m_A = " << p1.m_A << ", 地址:" <<&p1.m_A<<endl;
    cout << "p2.m_A = " << p2.m_A << ", 地址:" <<&p2.m_A<<endl;

    cout << "Person::m_A = " << Person::m_A << ", 地址:" <<&Person::m_A <<endl;
}

void test_static_variables_func()
{
    cout << "\n静态成员函数(static)：" << endl;
    cout << "1.所有对象共享同一个函数;\n";
    cout << "2.静态成员函数只能访问静态成员变量\n";
    void* a1 = union_cast<void*>(&Person::func);
    cout << "Person::func 地址:" <<a1<<endl;
    Person::func();
    Person p1;
    void* a2 = union_cast<void*>(&p1.func);
    cout << "p1调用静态成员函数, 地址:" <<a2<<endl;
    p1.func();
}





int main()
{

    test_static_variables();
    test_static_variables_func();
    return 0;
}

