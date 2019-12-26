#include <set>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

template <typename T>
void printSet(const set<T> &L) //采用模板实现各类型set的打印
{
    for (typename set<T>::const_iterator it = L.begin(); it != L.end(); it++)
        cout << *it << " ";
    cout << endl;
}

template <typename T>
void printmultiSet(const multiset<T> &L) //采用模板实现各类型set的打印
{
    for (typename multiset<T>::const_iterator it = L.begin(); it != L.end(); it++)
        cout << *it << " ";
    cout << endl;
}

template <typename T>
void printVector(const vector<T> &v)
{
    for (typename vector<T>::const_iterator it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
}

void test_create()
{
    cout << "1:创建，set特点" << endl;
    set<int> set1;           //自动排序，没有重复元素
    vector<int> v1;          //
    multiset<int> multiset1; //自动排序，可以有重读元素

    for (int i = 0; i < 10; i++)
    {
        int randnum;
        randnum = rand() % 10;
        set1.insert(randnum);
        v1.push_back(randnum);
        multiset1.insert(randnum);
    }
    cout << "vector:\t\t";
    printVector(v1);
    cout << "set:\t\t";
    printSet(set1);
    cout << "multiset:\t";
    printmultiSet(multiset1);
    cout << endl;

    set<int> set2(set1); //拷贝构造
    printSet(set2);

    set<int> set3;
    set3 = set2; //赋值
    printSet(set3);

    //从别的容器中：
    set<int> set_test(v1.begin(), v1.end() - 5);
    printVector(v1);
    printSet(set_test);
    cout << endl;
}

void test_size_swap()
{
    cout << "2:大小和交换" << endl;
    set<int> set1; //自动排序，没有重复元素

    for (int i = 0; i < 10; i++)
    {
        int randnum;
        randnum = rand() % 10;
        set1.insert(randnum);
    }
    cout << "set1:\t";
    printSet(set1);

    set<int> set2;
    for (int i = 1; i <= 10; i++)
        set2.insert(i);
    cout << "set2:\t";
    printSet(set2);

    cout << "empty?:\t" << set1.empty() << endl;
    cout << "size:\t" << set1.size() << endl;
    cout << "max_size:\t" << set1.max_size() << endl;

    set1.swap(set2);
    cout << "set1:\t";
    printSet(set1);
    cout << "set2:\t";
    printSet(set2);
    cout << endl;
}

void test_insert_delete()
{
    cout << "3:插入和删除" << endl;
    set<int> set1; //自动排序，没有重复元素

    for (int i = 0; i < 10; i++)
    {
        set1.insert(i);
    }
    cout << "set1:\n";
    printSet(set1);

    set<int>::iterator it = set1.begin();
    advance(it, 2);
    cout << *it << endl;
    cout << *set1.end() << endl; //索引

    set<int>::iterator it2 = it;
    cout << *it << " ";
    advance(it2, 2);
    cout << *it2 << endl;

    set<int>::iterator it_erase;
    printSet(set1);
    it_erase = set1.erase(it); //删除迭代器指向的元素,返回迭代器
    printSet(set1);
    cout << *it_erase << endl;

    set1.erase(5); //删除指定元素，不返回迭代器
    printSet(set1);

    // set1.erase(it, it2);
    // printSet(set1);
    cout << endl;
}

void test_find_count()
{
    cout << "4:查找和统计" << endl;
    set<int> set1;
    for (int i = 0; i < 10; i++)
        set1.insert(rand() % 10);
    printSet(set1);

    set<int>::iterator pos = set1.find(10); //返回指定元素的迭代器，如果没有找到，则返回set.end()
    cout << *pos << endl;                   //??,若是multiset的返回怎么办?multiset::equal_range
    cout << set1.count(2) << endl;

    cout << "multi:" << endl;
    int myints[] = {77, 30, 16, 2, 30, 30};
    multiset<int> mulset1(myints, myints + 6);
    printmultiSet(mulset1);
    cout << "相同元素有：" << mulset1.count(30) << "个." << endl;

    typedef multiset<int>::iterator mulit;
    pair<mulit, mulit> ret = mulset1.equal_range(30); //返回[first, second)     pair()
    //#include <utility>
    mulit ret2 = ret.first;
    advance(ret2, -1);

    // mulset1.erase(ret.first, ret.second);

    cout << *(ret.first) << endl;
    cout << "前一个元素:" << *ret2 << endl;
    cout << "后一个元素:" << *(ret.second) << endl;
    cout << endl;
}

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

struct intComp
{
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void test_sort()
{
    cout << "5:自定义排序:" << endl;
    int myints[] = {77, 0, 16, 2, 30, 55};
    set<int, MyCompare> set1(myints, myints + 6); //通过加入自定义结构体或者类

    for (auto it = set1.begin(); it != set1.end(); it++)
        cout << *it << " ";
    cout << endl;
    int myints1[] = {77, 0, 16, 2, 30, 55};
    set<int, intComp> set2(myints1, myints1 + 6); //通过加入自定义结构体或者类

    for (auto it = set2.begin(); it != set2.end(); it++)
        cout << *it << " ";
    cout << endl;
}

int main()
{
    test_create();
    test_size_swap();
    test_insert_delete();
    test_find_count();
    test_sort();
    return 0;
}