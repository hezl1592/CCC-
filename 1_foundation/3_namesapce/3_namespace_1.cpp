#include <iostream>
using namespace std;
#include "game1.h"
#include "game2.h"

void test0();
void test1();
void test2();

int main()
{
	test0();
	test1();
	test2();
	cout<<"DOTA命名空间中的goAtk："<<endl;
	DOTA::goAtk();
	cout<<"LOL命名空间中的goAtk："<<endl;
	LOL::goAtk();
	cout<<"Hello world"<<endl;
}


//命名空间主要用途：解决命名冲突的问题
//1.命名空间下可以放函数，变量、结构体、类等等
//2.命名空间必须定义在全局作用域下；
//3.命名空间可以嵌套命名空间

namespace A 	//命名空间A
{
	void func();	//函数
	int a=10;		//变量
	struct Person{};	//结构体
	class animal{};		//类
	namespace B 		//嵌套命名空间B
	{
		int a=20;
	}
}

//4.命名空间是开放的，可以随时在原先的命名空间中添加内容
namespace A     //此A命名空间会和上面的命名空间A进行合并
{
	int b=30;
}
//5.匿名、无名命名空间
//当写了无命名空间，相当于写了 static int c=0; static int d=7;
//只能在当前文件中使用
namespace
{
	int c=0;
	int d=7;
}
//6.命名空间可以起别名
namespace veryLongname
{
	int mm=60;
}

void test0()	//测试嵌套空间
{
	cout<<"test0: 测试嵌套空间"<<endl;
	cout<<"命名空间B中的a="<<A::B::a<<endl;
	cout<<"----------------------"<<endl;
}


void test1()	//测试命名空间的开放性
{
	cout<<"test1: 测试命名空间的开放性"<<endl;
	cout<<"命名空间A中的a="<<A::a<<", b="<<A::b<<endl;
	cout<<"----------------------"<<endl;
}


void test2()	//测试命名空间的别名
{
	cout<<"test2: 测试命名空间别名"<<endl;
	namespace veryshortname = veryLongname;		//起别名
	cout<<"起别名前: mm="<<veryLongname::mm<<endl;
	cout<<"起别名后: mm="<<veryshortname::mm<<endl;
	cout<<"----------------------"<<endl;
}
