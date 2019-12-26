#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printVector(vector<T> &v)
{
    //typename 很重要
    //如果传进来的参数是const的，那么iterator也需要是const_iterator才行
    for (typename vector<T>::iterator it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
}

// void printVector(vector<int> & v)
// {
//     for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//         cout << *it <<" ";
//     cout << endl;
// }

// void printVector(vector<char> & v)      //函数重载
// {
//     for (vector<char>::iterator it = v.begin(); it != v.end(); it++)
//         cout << *it <<" ";
//     cout << endl;
// }

void testcreate()
{
    cout << "1:构造" << endl;
    vector<int> v;  //构造无参数vector
    printVector(v); //没有参数

    for (int i = 0; i < 10; i++)
        v.push_back(i); ////尾部插入元素
    printVector(v);

    vector<int> v1(v.begin(), v.end());
    printVector(v1);

    vector<char> v2(10, 'h');
    printVector(v2);

    vector<char> v3(v2);
    printVector(v3);
}

void testassign()
{
    cout << "2:赋值操作" << endl;
    vector<int> v1; //无参构造
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2;
    v2 = v1;
    printVector(v2);

    vector<int> v3;
    v3.assign(v1.begin(), v1.end());
    printVector(v3);

    vector<int> v4;
    v4.assign(10, 100);
    printVector(v4);
    cout << endl;
}

void testsize()
{
    cout << "3:容量大小" << endl;
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    if (v1.empty())
    {
        cout << "v1为空" << endl;
    }
    else
    {
        cout << "v1不为空" << endl;
        cout << "v1的容量 = " << v1.capacity() << endl;
        cout << "v1的大小 = " << v1.size() << endl;
    }

    //resize 重新指定大小 ，若指定的更大，默认用0填充新位置，可以利用重载版本替换默认填充
    v1.resize(15, 10); //用10进行填充
    printVector(v1);

    //resize 重新指定大小 ，若指定的更小，超出部分元素被删除
    v1.resize(5);
    printVector(v1);
    cout << endl;
}

void testinsertanddelete()
{
    cout << "4:插入和删除" << endl;
    vector<int> v1;
    for (int i = 1; i <= 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    v1.pop_back(); //删除最后一个元素
    printVector(v1);

    // v1.insert(1, 11);    //不行，必须使用迭代器
    v1.insert(v1.begin() + 1, 11); //
    printVector(v1);

    v1.insert(v1.begin() + 5, 2, 22); //加入2个22
    printVector(v1);

    v1.erase(v1.begin() + 1);                 //删除迭代器指向的位置
    v1.erase(v1.begin() + 4, v1.begin() + 6); //删除迭代指向之间的位置
    printVector(v1);

    v1.clear();
    cout << v1.empty() << endl;
}

void testindex()
{
    cout << "5:索引操作" << endl;
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1.at(i) << " ";
    }
    cout << endl;

    cout << "v1的第一个元素为： " << v1.front() << endl;
    cout << "v1的最后一个元素为： " << v1.back() << endl;
    cout << endl;
}

void testswap()
{
    cout << "6:swap操作" << endl;
    cout << "6.1: 互换容器：" << endl;
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    cout << "原始：" << endl;
    cout << "v1:\t";
    printVector(v1);

    vector<int> v2;
    for (int i = 9; i >= 0; i--)
    {
        v2.push_back(i);
    }
    cout << "v2:\t";
    printVector(v2);

    //互换容器
    cout << "互换后:" << endl;
    v1.swap(v2);
    cout << "v1:\t";
    printVector(v1);
    cout << "v2:\t";
    printVector(v2);

    //缩减内存
    cout << "6.2:缩减内存：" << endl;
    vector<int> v;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }
    cout << "原始信息：" << endl;
    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为：" << v.size() << endl;

    v.resize(3);
    cout << "resize(3)后：" << endl;
    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为：" << v.size() << endl;

    //收缩内存
    vector<int>(v).swap(v); //匿名对象
    cout << "swap操作后：" << endl;
    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为：" << v.size() << endl;
}

void testreserve()
{
    //https://www.cnblogs.com/sunlightstoyou/p/10312258.html
    /*
    resize和reserve函数本质都涉及了vector的内存存储空间
    因为vector在内存中是连续存放的，
    所以当resize的空间大于现有的存储空间
    （capacity()函数返回当前vector在重新进行内存分配以前所能容纳的元素数量.）时
    会重新选择更大的空间，并将所有元素复制过去。
    resize在初始化内存容量时有对值的初始化，
    所以此时push_back会产生size+1，内存容量不够，
    重新寻找更大的内存空间并复制所有元素，所以这个过程是很费事的。
    */
    cout << endl;
    cout << "7:预留空间" << endl;
    vector<int> v;

    //预留空间
    v.reserve(100000);      //

    int num = 0;
    int *p = NULL;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
        if (p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }

    cout << "num:" << num << endl;
}

int main()
{
    testcreate();
    testassign();
    testsize();
    testinsertanddelete();
    testindex();
    testswap();
    testreserve();
    return 0;
}