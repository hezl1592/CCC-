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

void test_find()
{
    Person p1{"aaa", 10};
    Person p2{"bbb", 20};
    Person p3{"ccc", 30};
    Person p4{"ddd", 40};
    vector<Person> v2;
    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    v2.push_back(p4);

    Person p5(p2);

    vector<Person>::iterator it = find(v2.begin(), v2.end(), p5);
    if (it == v2.end())
        cout << "未找到" << endl;
    else
        cout << "找到姓名：" << it->m_mname << "\t年龄：" << it->m_age << endl;
}

class GreaerFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

void test_findif()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    vector<int>::iterator it = find_if(v1.begin(), v1.end(), GreaerFive());

    if (it == v1.end())
        cout << "未找到符合条件！" << endl;
    else
    {
        cout << "找到大于5的数字" << *it << endl;
    }
}

void test_adjacent_find()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    v.push_back(2);
    v.push_back(4);
    v.push_back(4);
    v.push_back(3);

    //查找相邻重复元素
    vector<int>::iterator it = adjacent_find(v.begin(), v.end());
    if (it == v.end())
    {
        cout << "找不到!" << endl;
    }
    else
    {
        cout << "找到相邻重复元素为:" << *it << endl;
    }
}

template <typename T>
void printVector(vector<T> &v)
{
    //typename 很重要
    //如果传进来的参数是const的，那么iterator也需要是const_iterator才行
    for (typename vector<T>::iterator it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
}

void test_binary_search()
{
    //二分查找法查找效率很高，值得注意的是查找的容器中元素必须的有序序列
    cout << "7:反转和排序" << endl;
    vector<int> v1;
    for (int i = 0; i < 10; i++)
        v1.push_back(rand() % 10);

    printVector(v1);

    sort(v1.begin(), v1.end()); //排序
    printVector(v1);

    bool ret = binary_search(v1.begin(), v1.end(), 2);
    cout << "找到与否?:" << ret << endl;
}

int main()
{
    vector<int> v1;
    for (int i = 9; i >= 0; i--)
    {
        v1.push_back(i);
    }
    cout << "v1:\t";
    for_each(v1.begin(), v1.end(), print01);
    cout << endl;

    vector<int>::iterator it = find(v1.begin(), v1.end(), 3); //没找到则返回.end()
    cout << "匹配值位置为：\t" << it - v1.begin() << endl;

    test_find();          //利用find可以在容器中找指定的元素，返回值是迭代器
    test_findif();        //find_if按条件查找使查找更加灵活，提供的仿函数可以改变不同的策略
    test_adjacent_find(); //查找相邻重复元素
    test_binary_search();   //二分法查找
    return 0;
}
