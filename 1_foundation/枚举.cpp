#include <iostream>

/*
枚举，
第一个枚举成员的默认值为整型的 0
后续枚举成员的值在前一个成员上加 1。
*/

enum weekday
{
    Mon = 1,
    Tus,
    Wed,
    Thru,
    Fri,
    Sat,
    Sun
};

enum test
{
    test1,
    test2 = 5,
    test3
};

int main()
{
    using namespace std;
    enum weekday day;

    day = Wed;
    cout << Sun << endl;
    cout << day << endl;

    cout << test1 << endl;
    cout << test3 << endl;
    return 0;
}