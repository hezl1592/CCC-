#include <iostream>

using namespace std;

void test1(), test2(), test3(), test4(),test5(),test6();

int main()
{
	cout<<"test1:";
	test1();
	cout<<"test2:";
	test2();
	cout<<"test3:";
	test3();
	cout<<"test4:";
	test4();
	cout<<"test5:";
	test5();
	cout<<"test6:";
	test6();
	return 0;
}

void test1()
{
	cout<<"变量地址"<<endl;
	int var1;
	char var2[10];
	cout<<"var1变量的地址："<<&var1<<endl;
	cout<<"var2变量的地址："<<&var2<<endl;
	cout<<"---------------------"<<endl;
}

void test2()
{
	cout<<"指针变量"<<endl;
	int var = 20;	//实际变量的声明
	int *ip;		//指针变量的声明
	ip = &var;		//在指针变量中存储var的地址
	cout<<"Value of var variable: "<<var<<endl;
	// 输出在变量指针中存储的地址
	cout<<"Address stored in ip variable: "<<ip<<endl;
	// 访问指针中地址的值
	cout<<"Value of *ip variable: "<<*ip<<endl;
	cout<<"---------------------"<<endl;
}


void test3()
{
	cout<<"NULL指针"<<endl;
	int *ptr=NULL;
	cout<<"ptr的值是"<<ptr<<endl;
	cout<<"---------------------"<<endl;
}

void test4()
{
	cout<<"指针的算术运算：递增（int型）"<<endl;
	const int MAX = 3;
	int var[MAX] = {10, 100, 200};
	cout<<var<<endl;
	int *ptr;
	// 指针中的数组地址
	ptr = var;
	for (int i = 0; i < MAX; i++)
	{
	cout << "Address of var[" << i << "] = ";
	cout << ptr << endl;
	cout << "Value of var[" << i << "] = ";
	cout << *ptr << endl;
	// 移动到下一个位置
	ptr++;
	}
	cout<<"---------------------"<<endl;
}

void test5()
{
	cout<<"指针的算术运算：递减（double型）"<<endl;
	const int MAX = 3;
	double var[MAX] = {10, 100, 200};
	cout<<var<<endl;
	double *ptr;
	// 指针中的数组地址
	ptr = var;
	for (int i = 0; i < MAX; i++)
	{
	cout << "Address of var[" << i << "] = ";
	cout << ptr << endl;
	cout << "Value of var[" << i << "] = ";
	cout << *ptr << endl;
	// 移动到下一个位置
	ptr--;
	}
	cout<<"---------------------"<<endl;
}


void test6()
{
	cout<<"指针的比较"<<endl;
	int MAX=3;
	int var[MAX] = {10, 100, 200};
	int *ptr;
	// 指针中第一个元素的地址
	ptr = var;
	int i = 0;
	// 指针的比较
	while ( ptr <= &var[MAX - 1] )
	{
	cout << "Address of var[" << i << "] = ";
	cout << ptr << endl;
	cout << "Value of var[" << i << "] = ";
	cout << *ptr << endl;
	// 指向上一个位置
	ptr++;
	i++;
	}
}
