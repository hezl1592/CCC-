#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string m_Name;
    int m_Age;
    string m_Lover;

public:
    //姓名设置可读可写
    void setName(string name)
    {
        m_Name = name;
    }
    string getName()
    {
        return m_Name;
    }

    //年龄设置可读可写
    void setAge(int age)
    {
        if (age < 0 || age > 150)
        {
            cout << "wrong age" <<endl;
            return;
        }
        m_Age = age;
    }
    int getAge()
    {
        return m_Age;
    }
    
    //爱人设置为只写
    void setLover(string lover)
    {
        m_Lover = lover;
    }
};

int main()
{
    using namespace std;

    Person p;
    p.setName("haha");
    cout << "姓名为："<<p.getName()<<endl;

    p.setAge(20);
    cout << "年龄为："<<p.getAge()<<endl;

    p.setLover("yiya");
//    cout << "爱人：" <<p.m_Lover <<endl;
    return 0;
}

