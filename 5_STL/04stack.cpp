#include <stack>
#include <iostream>

using namespace std;

template <typename T>
void printstack(stack<T> sta)
{
    stack<T> sta_temp = sta;        //赋值
    while (!sta_temp.empty())   //stack.empty()
    {
        cout << sta_temp.top() << " ";      //stack.top()
        sta_temp.pop();
    }
    cout << endl;
}

void test_stack()
{
    cout << "stack: FILO(first in last out)" << endl;
    //创建栈容器，FILO
    stack<int> sta1;
    for (int i = 0; i < 10; i++)
        sta1.push(i);
    printstack(sta1);

    cout << "size:\t" << sta1.size() << endl;
    cout << "栈顶:\t" << sta1.top() << endl;
    sta1.pop(); //弹出一个元素
    cout << "size:\t" << sta1.size() << endl;
    cout << "栈顶:\t" << sta1.top() << endl;
    cout << endl;
}

int main()
{
    test_stack();
    return 0;
}