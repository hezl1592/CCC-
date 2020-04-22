### 模板与泛型编程

---

面向对象编程和泛型编程都能处理在编写程序时不知道类型的情况。不同之处在于：OOP能处理类型在程序运行前都未知的情况，而在泛型编程中，在编译时就能获知类型。

所谓泛型编程就是以独立于任何特定类型的方式编写代码。

在C++里,通过**函数模板**和**类模板**来实现泛型编程。模板是C++中泛型编程的基础。

#### 1.函数模板

通用的函数模板就是一个公式，可用来生成针对特定类型的函数版本；

模板定义以关键字`template`开始，后跟一个**模板参数列表**。

```c++
template<typename T>	//template<typename T1, typename T2>
void Swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}
```

上述函数模板中，T表示的实际类型**在编译时**根据函数的使用情况来确定。

- **实例化函数模板**

  ```c++
  //实例化出int，Swap(int &a, int &b)
  Swap(1,0);		//自动推导T为int
  Swap<float>(0,1);	//指定
  ```

  调用函数模板的时候，编译器会用函数实参来推断模板实参，编译器用推断出的模板参数来为我们**实例化**一个特定版本的函数。这些编译器生成的版本通常被称为模板的**实例（instantiation）**。

  - **隐式实例化（implicit instantiation）**

    即编译器用函数实参推断模板实参，使用模板生成特定版本的函数定义。

  - **显式实例化（explicit instantiation）**

    即直接命令编译器生成特定的函数实例；

    ```c++
    template void Swap<int>(int, int);
    ```

  - **显式具体化（explicit specialization）**

    ```c++
    template <> void Swap<int>(int, int);
    ```

    ---

    **注意**：`在同一个文件（或转换单元）中使用同一种类型的显式实例和显式具体化会出错！！`
  
- 总结
  
    **隐式实例化**指的是：在使用模板之前，编译器不生成模板的声明和定义实例。只有当使用模板时，编译器才根据模板定义生成相应类型的实例。如：int i=0, j=1;swap(i, j);  //编译器根据参数i，j的类型隐式地生成swap<int>(int &a, int &b)的函数定义。Array<int> arVal;//编译器根据类型参数隐式地生成Array<int>类声明和类函数定义。
  
    **显式实例化**：当显式实例化模板时，在使用模板之前，编译器根据显式实例化指定的类型生成模板实例。如前面显示实例化（explicit instantiation）模板函数和模板类。其格式为：
  
    ```c++
      template typename function<typename>(argulist);
      template class classname<typename>;
    ```
  
  **显式实例化只需声明**，不需要重新定义。编译器根据模板实现实例声明和实例定义。
  
  **显示具体化**：*对于某些特殊类型，可能不适合模板实现，需要重新定义实现*，此时可以使用显示具体化（explicite specialization）。显示实例化需重新定义。格式为：

  ```c++
  template<> typename function<typename>(argu_list){...};
  template<> class classname<typename>{...};
  ```
  
- **模板类型参数**

  一般来说，我们可以将类型参数看做**类型说明符**，也可以用来指定返回类型或函数的参数类型，以及函数体内部用于变量声明或类型转换。

  ```c++
  template <typename T>
  T foo(T *p);
  
  template <typename T, typename U>
  T calc(const T&, const U&);
  ```

- **非类型模板参数**

  非类型参数表示一个值而非一个类型。我们用一个特定的类型名**而非**关键字`typename`或`class`老指定非类型参数；

  ```c++
  template<usigned N, usigned M>
  int compare(const char (&p1)[N], const char (&p2)[M])
  {
      return strcmp(p1,p2);
  }
  
  compare("hi", "mon");
  //实例化：
  int compare(const char (&p1)[3], const char (&p2)[4]);
  ```

  非类型参数可以是一个整型、或者是一个指向对象或函数原型的指针或引用。

  在模板定义内，非类型参数是一个常量值。在需要常量表达式的地方，可以使用非类型参数，比如指定数组大小。

  - 非类型模板参数的模板实参必须是常量表达式`const`


#### 2.类模板

**类模板**（class template）是用来生成类的蓝图的。与函数模板的不同之处在于，编译器不能为类模板推断模板参数类型，必须制定类型。

```c++
vector<int> ob_name;
```

- 定义类模板

```c++
template<typename Type>
class Blob {
public:
    Blob();
    ~Blob();
    
    void show(const Blob &);
}

template<typename Type>
void Blob<Type>::show(const Blob &bl);
```

- 实例化类模板

  当使用类模板时，必须提供额外信息，**显式模板实参**！

- 类模板与友元

  ```c++
  template<typename Type>
  class Blob {
  public:
      Blob();
      ~Blob();
      
      void show(const Blob &);
      friend class Blobptr<Type>;
      friend bool operator==<Type>(const Blob<Type>&, const Blob<T> &);
  }
  ```

- 