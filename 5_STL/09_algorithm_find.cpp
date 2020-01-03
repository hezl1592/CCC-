#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print01(int val)
{
    cout << val << " ";
}
class Person //
{
public:
    Person(string name, int age)
    {
        this->m_mname = name;
        this->m_age = age;
    }

    bool operator==(const Person &P)
    {
        if (this->m_mname == P.m_mname && this->m_age == P.m_age)
        {
            return true;
        }
        return false;
    }

public:
    string m_mname;
    int m_age;
};

int main()
{
    vector<int> v1;
    for (int i = 9; i >=0; i--)
    {
        v1.push_back(i);
    }
    cout << "v1:\t";
    for_each(v1.begin(), v1.end(), print01);
    cout << endl;

    vector<int>::iterator it = find(v1.begin(), v1.end(), 3);
    cout << "匹配值位置为：\t" << it - v1.begin() <<endl;

    return 0;
}

