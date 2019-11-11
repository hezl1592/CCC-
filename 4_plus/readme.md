进阶

#### 1. 引用

##### 1.1 基本使用

​	**作用: **给变量起别名；

​	语法：==数据类型 &别名 = 原名==

​	实例:

```c++
void reference_test1()
{
    using namespace std;
    cout << "基本使用" <<endl;
 
    int a = 10;
    int &b = a;
    
    cout << "a = "<<a <<endl;
    
    b = 100;
    cout << "a = "<<a <<endl;
    cout << "b = "<<b <<endl;
}  
```

##### 1.2 引用注意事项

- 引用必须初始化；
- 应用在初始化后，不可以改变；

##### 1.3 引用做函数参数

- 函数传参时，可以利用引用的技术让星灿修饰实参
- 简化指针修改实参

```c++
//1. 值传递
void mySwap01(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

//2. 地址传递
void mySwap02(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//3. 引用传递
void mySwap03(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {

	int a = 10;
	int b = 20;

	mySwap01(a, b);
	cout << "a:" << a << " b:" << b << endl;

	mySwap02(&a, &b);
	cout << "a:" << a << " b:" << b << endl;

	mySwap03(a, b);
	cout << "a:" << a << " b:" << b << endl;

	system("pause");

	return 0;
}
```

##### 2.4 引用做函数返回值

作用：引用可以作为函数的返回值存在

注意：不要返回局部变量引用

用法：函数调用作为左值

```c++
//返回局部变量引用
int& test01() {
	int a = 10; //局部变量
	return a;
}

//返回静态变量引用
int& test02() {
	static int a = 20;
	return a;
}

int main() {

	//不能返回局部变量的引用,出错！
	int& ref = test01();
	cout << "ref = " << ref << endl;
	cout << "ref = " << ref << endl;

	//如果函数做左值，那么必须返回引用
	int& ref2 = test02();
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	test02() = 1000;

	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;

	system("pause");

	return 0;
}
```



