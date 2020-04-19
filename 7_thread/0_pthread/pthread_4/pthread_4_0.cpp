/*
Filename: pthread_4_0.cpp
Created by Zilch on 2020/4/18.
*/
#include "pthread_4_worker.h"

//using namespace std;
extern int counter;

int main() {
    test_without();         //没有进行同步的测试计算函数
    test_with_mutex();      //用了mutex的同步测试计算函数
    test_with_condition();  //使用条件变量和mutex的同步生产者消费者
    return 0;
}