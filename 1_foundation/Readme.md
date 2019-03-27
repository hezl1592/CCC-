### Foundation
#### 1. 基础概念

- #include：对编译器打出的操作指令，指示编译器在编译之前，现将<>中的文件内容在本文件中展开。

```c++
#include<iostream>     //标准输入、输出的标准库头文件

using namespace std;    //命名空间，std::

void sphere();       //声明函数

//主函数，程序的入口，从main() 开始执行程序，int 表示main()函数应该返回一个整型值。
int main(){
	sphere();       //调用sphere函数
}

void sphere(){
	double radius;
	cout<<"Please input radius: ";
	cin>>radius;
	if(radius<0) return;
	cout<<"The result is "<<radius*radius*3.14*4<<"\n";
}
```

- Namespace

C++ 程序的入口总是int main()

- endl

输出换行病刷新缓冲区

```c++
cout<<""<<endl
```



#### 2.基础编程语句

##### 2.1. if语句

```c++
if(条件) 语句
if(条件) 语句1 else 语句2
```

