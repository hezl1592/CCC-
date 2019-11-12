#include <iostream>

using namespace std;
class Person
{
public:
    int m_age;
    int *m_height;

public:
    Person()
    {
        cout << "无参构造函数"<<endl;
    }
    Person(int age, int height)
    {
        cout << "有参构造函数" <<endl;
        m_age = age;
        m_height = new int(height);
    }
    //自定构造函数实现深拷贝。
    Person(const Person& p)
    {
        cout << "拷贝构造函数"<<endl;
        m_age = p.m_age;
        m_height = new int(*p.m_height);
    }
    ~Person()
    {
        cout << "析构函数"<<endl;
        if (m_height != NULL)
        {
            //释放堆区内存
            delete m_height;
        }
    }
};


int main()
{
    cout << "创建p1:\n";
    Person p1(18,170);
    cout << "p1年龄："<<p1.m_age << "，身高："<<*p1.m_height<<endl;
    cout << "创建p2:\n";
    Person p2(p1);
    cout << "p2年龄："<<p2.m_age << "，身高："<<*p2.m_height<<endl;

    std::cout << "Hello world" << std::endl;
    return 0;
}

