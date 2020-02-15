## 友元
- 友元函数；
- 友元类；
- 友元成员函数;

#### 1.友元函数
通过使函数成为类的友元，可以赋予该函数与类的成员函数相同的访问权限。
1. 创建友元
在类的内部声明，关键字**friend**。
在类的外部进行定义。
```c++
class Box
{
private:
    double width;
public:
    double length;
    void setWidth(double wid);
    friend void printWidth(Box box);
}
```

```c++
void Box::setWidth(double wid)
{
    width = wid;
}

void printWidth(Box box)
{
    cout << "Width = " <<box.width <<endl;
}
```