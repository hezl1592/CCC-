#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print01(int val);
class print02
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

void test_for_each(vector<int> &v);
void test_transform(vector<int> &v);
int trans_Transform(int val);

int main()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    test_for_each(v1);
    test_transform(v1);
    return 0;
}

void print01(int val)
{
    cout << val << " ";
}

void test_for_each(vector<int> &v)
{
    // for_each(v.begin(), v.end(), print01);       //两种方法均可
    for_each(v.begin(), v.end(), print02());
    cout << endl;

    for_each(v.begin(), v.begin() + 5, print01);
    cout << endl;
}

int trans_Transform(int val)
{
    return val;
}

void test_transform(vector<int> &v)
{
    //转移容器
    vector<int> v2;
    v2.resize(v.size());        // 搬运的目标容器必须要提前开辟空间，否则无法正常搬运

    transform(v.begin(), v.end(), v2.begin(), trans_Transform);
    cout << "v2:\t";
    for_each(v2.begin(), v2.end(), print01);
    cout <<endl;
}