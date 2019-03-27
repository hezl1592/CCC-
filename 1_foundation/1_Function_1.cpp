#include<iostream>     //标准输入、输出的标准库头文件

using namespace std;    //命名空间，std::

void sphere();		//声明函数

//主函数，程序的入口，从main() 开始执行程序，int 表示main()函数应该返回一个整型值。
int main(){
	sphere();       //调用sphere函数
}

void sphere(){
	double radius;		//声明变量类型
	cout<<"Please input radius: ";		//打印
	cin>>radius;		//输入 赋予变量值
	if(radius<0) return;		//判断语句
	cout<<"The result is "<<radius*radius*3.14*4<<"\n";
}