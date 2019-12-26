#include <iostream>
#include <map>

using namespace std;

template <typename T>
void printMap(const map<T, T> &map1)
{
    for (typename map<T, T>::const_iterator it = map1.begin(); it != map1.end(); it++)
        cout << "key=" << it->first << " value=" << it->second << endl;
    cout << endl;
}

void test_create()
{
    cout << "1:创建和赋值、大小和交换" << endl;
    map<int, int> m1;
    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(2, 20));
    m1.insert(pair<int, int>(3, 30));
    m1.insert(pair<int, int>(4, 40)); //map中所有元素都是成对出现，插入数据时候要使用对组
    printMap(m1);

    map<int, int> m2 = m1; //
    printMap(m2);

    map<int, int> m3(m1); //拷贝构造
    printMap(m3);

    map<int, int>::iterator it = m1.begin();
    advance(it,2);
    map<int, int> m4(m1.begin(), it); //拷贝构造
    printMap(m4);

    cout << "m1大小为:\t\t" << m1.size() << endl;
    cout << "m4大小为:\t\t" << m4.size() << endl;
    cout << "empty?:\t\t" << m1.empty() << endl;

    m4.swap(m1);
    cout << "after swap:" << endl;
    cout << "m1大小为:\t\t" << m1.size() << endl;
    cout << "m4大小为:\t\t" << m4.size() << endl;
    cout << endl;
}

int main()
{
    test_create();
    return 0;
}