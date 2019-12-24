#include <iostream>
#include <string>
#include <fstream>
// #include <cstdlib>

using namespace std;

void string_creat()
{
    //string()
    string m1;      //声明类型
    m1 = "fafasfa"; //初始化
    cout << m1 <<endl;

    //string(const char* s)
    string one("hezliang"); //初始化
    cout << one <<endl;

    //string(size_type n, char c)
    string two(20, 'L');
    cout << two <<endl;

    //string(string &str)
    string three(two);
    cout << three<< endl;

    three += one;
    cout << three << endl;

    three[0] = 'H';
    cout << three << endl;

    char alls[] = "he zi liang";
    string all_string(alls, 8);     //
    cout << alls <<endl;
    cout << all_string <<endl;
    string each_string(all_string, 2); //注意一下
    cout << each_string <<endl;
    
    string six(alls+0, alls+5);
    cout << six <<endl;
    string six_1(&alls[0], &alls[5]);
    cout << six_1 <<endl;

    string seven_1(one, 2, 7);
    string seven(one, 2, 1000);     //越界则到最后
    string seven_2(alls, 1, 1000);
    cout << seven <<endl;
    cout << seven_1 <<endl;
    cout << seven_2 <<endl;

}

void read_txt()
{
    ifstream fin;
    fin.open("string.txt");
    if (fin.is_open() == false)
    {
        cout << "Can't open the file" <<endl;
        return;
    }
    string item;
    int count = 0;
    getline(fin, item);
    while (fin)
    {
        ++count;
        cout << count<< ": " <<item<<endl;
        getline(fin, item);

    }
    cout << "Done!" <<endl;
    fin.close();
}

void read_txt1()
{
    ifstream fin;
    fin.open("string.txt");
    if (fin.is_open() == false)
    {
        cout << "Can't open the file" <<endl;
        return;
    }
    string item;
    int count = 0;
    getline(fin, item, ':');
    while (fin)
    {
        ++count;
        cout << count<< ": " <<item<<endl;
        getline(fin, item, ':');          //制定分界字符后，换行符将会被视为常规字符

    }
    cout << "Done!" <<endl;
    fin.close();
}

int main()
{
    string_creat();
    read_txt();
    read_txt1();
    return 0;
}