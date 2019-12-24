## STL

- STL（Standard Template Library，标准模板库）

- STL 从广义上分为: **容器(container) 、算法(algorithm) 、迭代器(iterator)**

- **容器**和**算法**之间通过**迭代器**进行无缝连接。
- STL 几乎所有的代码都采用了模板类或者模板函数

- STL大体分为六大组件，分别是:**容器、算法、迭代器、仿函数、适配器（配接器）、空间配置器**
  1. 容器：各种数据结构，如vector、list、deque、set、map等,用来存放数据。
  2. 算法：各种常用的算法，如sort、find、copy、for_each等。
  3. 迭代器：扮演了容器与算法之间的胶合剂。
  4. 仿函数：行为类似函数，可作为算法的某种策略。
  5. 适配器：一种用来修饰容器或者仿函数或迭代器接口的东西。
  6. 空间配置器：负责空间的配置与管理。

- **容器：**置物之所也

  STL**容器**就是将运用**最广泛的一些数据结构**实现出来

  常用的数据结构：数组, 链表,树, 栈, 队列, 集合, 映射表 等

  这些容器分为**序列式容器**和**关联式容器**两种:

   **序列式容器**:强调值的排序，序列式容器中的每个元素均有固定的位置。 **关联式容器**:二叉树结构，各元素之间没有严格的物理上的顺序关系

- **算法：**问题之解法也

  有限的步骤，解决逻辑或数学上的问题，这一门学科我们叫做算法(Algorithms)

  算法分为:**质变算法**和**非质变算法**。

  质变算法：是指运算过程中会更改区间内的元素的内容。例如拷贝，替换，删除等等

  非质变算法：是指运算过程中不会更改区间内的元素内容，例如查找、计数、遍历、寻找极值等等

- **迭代器：**容器和算法之间粘合剂

  提供一种方法，使之能够依序寻访某个容器所含的各个元素，而又无需暴露该容器的内部表示方式。

  每个容器都有自己专属的迭代器，迭代器使用非常类似于指针，初学阶段我们可以先理解迭代器为指针

#### 1. 容器

##### 1.1 string

- 基本概念

  string是C++风格的字符串，而string本质上是类

  - string和char * 的区别：

    char * 是一个指针；

    string是一个类，类内部封装了char* ，管理这个字符串，是一个char * 型的容器

- 特点：

  string类内部封装了很多成员方法；

  例如查找find、拷贝copy、删除delete等等。

###### 1.1.1 string构造

常用：

- `string();` //创建一个空的字符串 

  例如: string str; `string(const char* s);` //使用字符串s初始化

- `string(const string& str);` //使用一个string对象初始化另一个string对象

- `string(int n, char c);` //使用n个字符c初始化

![1577182744701](../0_image/string构造原型.png)

###### 1.1.2 string赋值操作

给string字符串进行赋值；

赋值的函数原型：

- `string& operator=(const char* s);` //char*类型字符串 赋值给当前的字符串
- `string& operator=(const string &s);` //把字符串s赋给当前的字符串
- `string& operator=(char c);` //字符赋值给当前的字符串
- `string& assign(const char *s);` //把字符串s赋给当前的字符串
- `string& assign(const char *s, int n);` //把字符串s的前n个字符赋给当前的字符串
- `string& assign(const string &s);` //把字符串s赋给当前字符串
- `string& assign(int n, char c);` //用n个字符c赋给当前字符串

###### 1.1.3 string拼接操作

​	实现在字符串末尾拼接字符串

​	**函数原型：**

- `string& operator+=(const char* str);` //重载+=操作符
- `string& operator+=(const char c);` //重载+=操作符
- `string& operator+=(const string& str);` //重载+=操作符
- `string& append(const char *s); `//把字符串s连接到当前字符串结尾
- `string& append(const char *s, int n);` //把字符串s的前n个字符连接到当前字符串结尾
- `string& append(const string &s);` //同operator+=(const string& str)
- `string& append(const string &s, int pos, int n);`//字符串s中从pos开始的n个字符连接到字符串结尾

###### 1.1.4 string查找和替换

​	**功能描述：**

- 查找：查找指定字符串是否存在

  ![1577185627068](../0_image\1577185627068.png)

- 替换：在指定的位置替换字符串

  **函数原型：**

- `int find(const string& str, int pos = 0) const;` //查找str第一次出现位置,从pos开始查找

- `int find(const char* s, int pos = 0) const; `//查找s第一次出现位置,从pos开始查找

- `int find(const char* s, int pos, int n) const; `//从pos位置查找s的前n个字符第一次位置

- `int find(const char c, int pos = 0) const; `//查找字符c第一次出现位置

- `int rfind(const string& str, int pos = npos) const;` //查找str最后一次位置,从pos开始查找

- `int rfind(const char* s, int pos = npos) const;` //查找s最后一次出现位置,从pos开始查找

- `int rfind(const char* s, int pos, int n) const;` //从pos查找s的前n个字符最后一次位置

- `int rfind(const char c, int pos = 0) const; `//查找字符c最后一次出现位置

- `string& replace(int pos, int n, const string& str); `//替换从pos开始n个字符为字符串str

- `string& replace(int pos, int n,const char* s); `//替换从pos开始的n个字符为字符串s

###### 1.1.5 string字符串比较

- 字符串之间的比较

- 字符串比较是按字符的ASCII码进行对比

**函数原型：**

- `int compare(const string &s) const; `//与字符串s比较
- `int compare(const char *s) const;` //与字符串s比较

###### 1.1.6 string字符的索引

string中单个字符存取方式有两种

- `char& operator[](int n); `//通过[]方式取字符
- `char& at(int n); `//通过at方法获取字符