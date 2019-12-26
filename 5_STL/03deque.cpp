#include <iostream>
#include <deque>
#include <algorithm>
#include <stdlib.h>

using namespace std;

template <typename T>
void printDeque(const deque<T> &d)
{
    for (typename deque<T>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void testcreate()
{
    cout << "1:构造" << endl;
    deque<int> d1;
    for (int i = 0; i < 10; i++)
        d1.push_back(i);
    printDeque(d1);

    deque<int> d2(d1.begin(), d1.end() - 1);
    printDeque(d2);

    deque<int> d3(10, 100);
    printDeque(d3);

    deque<int> d4 = d3;
    printDeque(d4);

    //assign
    deque<int> d5;
    d5.assign(d1.begin(), d1.end());
    printDeque(d5);

    deque<char> d6;
    d6.assign(10, 'h');
    printDeque(d6);

    cout << endl;
}

void testsize()
{
    cout << "2:大小和容量" << endl;
    deque<int> d1;
    for (int i = 0; i < 10; i++)
        d1.push_back(i);
    printDeque(d1);
    cout << "size:\t" << d1.size() << endl;
    d1.resize(15, 0);
    printDeque(d1);
    cout << "size:\t" << d1.size() << endl;

    d1.resize(5, 0);
    printDeque(d1);
    cout << "size:\t" << d1.size() << endl;

    d1.clear(); //清空
    cout << d1.empty() << endl;
    cout << endl;
}

void test_insert_delete()
{
    cout << "3:插入和删除" << endl;
    deque<int> d1;
    for (int i = 9; i >= 0; i--)
    {
        d1.push_back(i);  //在容器尾部添加一个数据
        d1.push_front(i); //在容器头部插入一个数据
    }
    printDeque(d1);

    for (int i = 5; i > 0; i--)
    {
        d1.pop_back(); //删除容器最后一个数据
    }
    printDeque(d1);

    for (int i = 5; i > 0; i--)
    {
        d1.pop_front(); //删除容器第一个数据
    }
    printDeque(d1);

    //!!迭代器
    cout << endl;
    deque<int> d2;
    for (int i = 0; i < 10; i++)
        d2.push_back(i);
    printDeque(d2);
    d2.insert(d2.begin() + 1, 20); // 在pos位置插入一个elem元素的拷贝，返回新数据的位置。
    d2.insert(d2.end(), 2, 100);   //
    printDeque(d2);

    d2.erase(d2.end() - 2, d2.end()); //删除[beg,end)区间的数据
    d2.erase(d2.begin() + 1);
    printDeque(d2);

    d2.insert(d2.end(), d1.begin(), d1.end()); //可以插入其他容器中的数据
    printDeque(d2);
    // d2.insert(d2.end(), 2, 100);

    d2.clear();
    cout << d2.empty() << endl;
    cout << endl;
}

void test_index()
{
    cout << "4:索引" << endl;
    deque<int> d2;
    for (int i = 0; i < 10; i++)
        d2.push_back(i);
    printDeque(d2);

    for (int i = 0; i < 10; i++)
    {
        cout << d2[i] << " ";     //[]
        cout << d2.at(i) << endl; //at
    }

    cout << "d的第一个元素为： " << d2.front() << endl;
    cout << "d的最后一个元素为： " << d2.back() << endl;
    cout << endl;
}

bool sort_(int i, int j)
{
    return (i > j);
}

void test_sort()
{
    cout << "5:sort" << endl;
    deque<int> d2;
    for (int i = 0; i < 10; i++)
        d2.push_back(rand() % 10);
    printDeque(d2);

    sort(d2.begin(), d2.end()); //默认升序
    cout << "after sort" << endl;
    printDeque(d2);

    sort(d2.begin(), d2.end(), sort_); //实现降序排序，第三个参数为回调函数，实现排序方法
    printDeque(d2);
}

int main()
{
    testcreate();
    testsize();
    test_insert_delete();
    test_index();
    test_sort();
    return 0;
}
