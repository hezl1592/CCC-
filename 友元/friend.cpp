#include <iostream>

class Box
{
private:
    double width;

public:
    double length;
    void setWidth(double wid);
    //友元函数
    friend void printWidth(Box box);
};

void Box::setWidth(double wid)
{
    width = wid;
}

void printWidth(Box box)
{
    using std::cout;
    using std::endl;
    cout << "Width = " <<box.width <<endl;
}

int main()
{
    Box newbox;

    newbox.setWidth(10.0);

    printWidth(newbox);

    return 0;
}