#include <iostream>

using namespace std;

class Person
{
public:
    int age;

    Person(int age)
    {
        this->age = age; 
    }

    void PersonAddAge(Person &p)
    {
        this->age += p.age;
    }

    Person a_PersonAddAge(Person &p)
    {
        this->age += p.age;
    }
    Person b_PersonAddAge(Person p)
    {
        this->age += p.age;
    }
};

void test()
{
    Person p1(10);
    cout << "p1.age = " << p1.age <<endl;
    Person p2(p1);
    cout << "p2.age = " << p2.age <<endl;
    p2.PersonAddAge(p1);
    cout << "p2.age = " << p2.age <<endl;
    p2.a_PersonAddAge(p1);
    cout << "p2.age = " << p2.age <<endl;
    p2.b_PersonAddAge(p1);
    cout << "p2.age = " << p2.age <<endl;
    cout << "p2.age = " << p2.age <<endl;

}

int main()
{
    test();
    return 0;
}

