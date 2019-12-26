#include <iostream>
#include <queue>

using namespace std;

template <typename T>
void printqueue(queue<T> que)
{
    queue<T> que_temp = que;
    cout << "队列长度：\t" << que_temp.size() << endl;
    cout << "队列头：\t" << que_temp.front() << endl;
    cout << "队列为：\t" << que_temp.back() << endl;
    while (!que_temp.empty())
    {
        cout << que_temp.front() << " ";
        que_temp.pop();
    }
    cout << endl;
}

void test_queue()
{
    cout << "queue: FIFO(first in first out)" << endl;
    //创建栈容器，FILO
    queue<int> que1;
    for (int i = 0; i < 10; i++)
        que1.push(i);
    printqueue(que1);
}

int main()
{
    test_queue();
    return 0;
}