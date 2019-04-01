### Foundation
#### 1. 基础概念

- 面向对象三大特性

  - 封装

  将客观事物封装成抽象的类，并且类可以把自己的数据和方法只让可信的类或者对象操作，对不可信的进行消息隐藏。

  - 继承

  继承所表达的是类之间相关的关系，这种关系使得对象可以继承另外一类对象的特征和能力；

  继承的作用：避免公用代码的重复开发，减少代码和数据的冗余。

  - 多态

  多态可以简单地概括为“一个接口，多种方法”，字面意思为多种形态，程序在运行时才决定调用的函数，它是面向对象变成领域的核心概念。

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

