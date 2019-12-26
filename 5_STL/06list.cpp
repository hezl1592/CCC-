#include <list>
#include <iostream>
#include <stdlib.h> //rand

using namespace std;

template <typename T>
void printList(const list<T> &L) //采用模板实现各类型list的打印
{
    for (typename list<T>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test_create()
{
    cout << "1:构造" << endl;
    list<int> list1;
    for (int i = 0; i < 10; i++)
        list1.push_back(i); //尾部插入元素
    printList(list1);

    list<int> list2(list1.begin(), list1.end());
    printList(list2);

    list<int> list3(list2);
    printList(list3);

    list<char> list4(10, 'h');
    printList(list4);
    // list<int> list3;
    // list3.assign(list1.begin(), list1.begin()+1);        //猜测不是连续的内存
    cout << endl;
}

void test_assign()
{
    cout << "2:赋值和交换" << endl;
    char example[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> list1;
    list1.assign(example, example + 10);
    cout << "list1:\t";
    printList(list1);

    list<int> list2 = list1;
    cout << "list2:\t";
    printList(list2);

    list<int> list3;
    list3.assign(list2.begin(), list2.end());
    cout << "list3:\t";
    printList(list3);

    list<int> list4;
    list4.assign(example, example + 5);
    cout << "list4:\t";
    printList(list4);

    list4.swap(list1);
    cout << "swap操作后：" << endl;
    cout << "list1:\t";
    printList(list1);
    cout << "list4:\t";
    printList(list4);
    cout << endl;
}

void test_size()
{
    cout << "4:大小操作" << endl;
    char example[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> list1;
    list1.assign(example, example + 10);
    // cout << "list1:\t";
    printList(list1);

    cout << "list.empty?:\t" << list1.empty() << endl;
    list1.resize(20, 0);
    printList(list1);

    list1.resize(5);
    printList(list1);
    cout << list1.size() << endl;

    list1.clear(); //清空
    cout << "list.empty?:\t" << list1.empty() << endl;
    cout << list1.size() << endl;
    cout << endl;
}

void test_insert_delete()
{
    cout << "5:插入和删除" << endl;
    list<int> list1;
    for (int i = 0; i < 10; i++)
    {
        list1.push_back(i);
        list1.push_front(i);
    }
    cout << "list1:\t";
    printList(list1);

    for (int i = 5; i--; i > 0)
    {
        list1.pop_back();  //删除尾部
        list1.pop_front(); //删除头部
    }
    printList(list1);

    //插入
    list<int>::iterator it = list1.begin();
    advance(it, 4); //配合advance插入指定位置
    advance(it, -2);
    list1.insert(it, 100);
    list1.insert(it, 2, 66);
    printList(list1);

    list1.remove(66); //删除指定元素
    printList(list1);

    list<int>::iterator it1 = it;
    advance(it1, 2);

    list1.erase(--it);
    printList(list1);
    list1.erase(it, it1); //删除[beg,end)区间的数据，返回下一个数据的位置。
    printList(list1);
    cout << endl;
}

void test_data()
{
    cout << "6:获取数据" << endl;
    char example[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> list1;
    list1.assign(example, example + 10);
    printList(list1);

    cout << "第一个数据:\t\t" << list1.front() << endl;
    cout << "最后一个数据:\t" << list1.back() << endl;
    cout << endl;

    list<int>::iterator it = list1.begin();
    int pos = 4;
    advance(it, pos);
    cout << "第" << pos + 1 << "位元素为:\t" << *it << endl;
    cout << endl;
}

bool myCompare(int val1, int val2)
{
    return val1 > val2;
}

void test_reverse_sort()
{
    cout << "7:反转和排序" << endl;
    list<int> list1;
    for (int i = 0; i < 10; i++)
        list1.push_back(rand() % 10);
    printList(list1);

    list1.reverse();
    printList(list1);

    list1.sort();
    printList(list1);

    list1.sort(myCompare); //逆序
    printList(list1);
    cout << endl;

    // sort(list1.begin(), list1.end());  //std:sort() 所使用的容器必須能支持隨機存取, 如: std::vector
    // printList(list1);

    cout << endl;
}

int main()
{
    test_create();
    test_assign();
    test_size();
    test_insert_delete();
    test_data();
    test_reverse_sort();
    return 0;
}