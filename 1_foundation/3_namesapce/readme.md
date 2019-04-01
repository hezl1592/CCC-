#### Namespace
命名空间主要用途：解决命名冲突的问题
1. 命名空间下可以放函数，变量、结构体、类等等;
2. 命名空间必须定义在全局作用域下；
3. 命名空间可以嵌套命名空间;

```c++
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

```

4. 命名空间是开放的，可以随时在原先的命名空间中添加内容

```c++
namespace A     //此A命名空间会和上面的命名空间A进行合并
{
	int b=30;
}
```

5. 匿名、无名命名空间: 当写了无命名空间，相当于写了 static int c=0; static int d=7; 只能在当前文件中使用

```c++
namespace
{
	int c=0;
	int d=7;
}
```

6. 命名空间可以起别名

```c++
namespace origin_name = new_name;
```

