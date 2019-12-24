#include <iostream>
#include <string>
//string构造
using namespace std;

void test()
{
	cout << "0:string大小和容量"<<endl;
	string str1;
	cout << "空字符串："<<str1 <<endl;

	cout << "size:\t" << str1.size() <<endl;
	cout << "length:\t" << str1.length() <<endl;
	cout << "capacity:\t" <<str1.capacity() <<endl;	//当前string类在不重新分配的情况下，能存多少字符
	cout << "size_of:\t" << sizeof(str1) <<endl;
	cout << "max_size:\t" <<str1.max_size() <<endl;	//string 类型对象最多包含的字符数


	string str = "heziliang";
	cout << "原始字符串："<<str <<endl;

	cout << "size:\t" << str.size() <<endl;
	cout << "length:\t" << str.length() <<endl;
	cout << "capacity:\t" <<str.capacity() <<endl;	//当前string类在不重新分配的情况下，能存多少字符
	cout << "size_of:\t" << sizeof(str) <<endl;
	cout << "max_size:\t" <<str.max_size() <<endl;	//string 类型对象最多包含的字符数

	string str2 = "hezilianglllllllllllll";
	cout << "原始字符串："<<str2 <<endl;

	cout << "size:\t" << str2.size() <<endl;
	cout << "length:\t" << str2.length() <<endl;
	cout << "capacity:\t" <<str2.capacity() <<endl;	//当前string类重新分配的情况
	cout << "size_of:\t" << sizeof(str2) <<endl;
	cout << "max_size:\t" <<str2.max_size() <<endl;	//string 类型对象最多包含的字符数
}

void test01()
{
	cout << "1:构造操作" <<endl;
	string s1; //创建空字符串，调用无参构造函数
	cout << "str1 = " << s1 << endl;

	const char* str = "hello world";
	string s2(str); //把c_string转换成了string

	cout << "str2 = " << s2 << endl;

	string s3(s2); //调用拷贝构造函数
	cout << "str3 = " << s3 << endl;

	string s4(10, 'a');
	cout << "str3 = " << s3 << endl;
}

void test02()
{
	cout << "2:赋值操作" <<endl;

	string str1;
	str1 = "hello world";  //char*类型字符串 赋值给当前的字符串
	cout << "str1 = " << str1 << endl;

	string str2;
	str2 = str1;		//把字符串s赋给当前的字符串
	cout << "str2 = " << str2 << endl;

	string str3;
	str3 = 'a';			//字符赋值给当前的字符串
	cout << "str3 = " << str3 << endl;

	string str4;
	str4.assign("hello c++");
	cout << "str4 = " << str4 << endl;

	string str5;
	str5.assign("hello c++",5);
	cout << "str5 = " << str5 << endl;


	string str6;
	str6.assign(str5);
	cout << "str6 = " << str6 << endl;

	string str7;
	str7.assign(5, 'x');
	cout << "str7 = " << str7 << endl;
}


void test_find()
{
	cout << "3:查找操作" <<endl;
	string str("heziliang");
	cout << "原始字符串："<<str <<endl;

	int pos1 = str.find('i', 0);		//查找字符，从左边0个位置开始，第一次出现的位置
	cout << pos1 << endl;				
	int pos11 = str.find('w', 0);		//未找到返回-1
	cout << pos11 <<endl;
	int pos12 = str.find("zi", 0);		//查找字符串
	cout << pos12 << endl;

	int pos2 = str.rfind('i');
	cout << pos2 <<endl;
	int pos21 = str.rfind("zi");
	cout << pos21 <<endl;
}

void test_replace()
{
	cout << "4:替换操作" <<endl;
	string str("heziliang");
	cout << "原始字符串："<<str <<endl;

	//不能替换字符
	str.replace(0, 3, "hahaha"); 	//替换从0位置开始3个字符为字符串“hahaha”
	cout << str <<endl;
}

void test_append()
{
	cout << "5:拼接操作" <<endl;
	string str("heziliang");
	cout << "原始字符串："<<str <<endl;

	string str1;
	str1 += str;
	cout << str1 <<endl;

	str1.append(str);
	cout << str1 <<endl;

	str1.append(str, 2);
	cout << str1 <<endl;
}

void test_compare()
{
	cout <<"6:比较操作"<<endl;
	string s1 = "hello";
	string s2 = "gello";
	cout << "s1=" << s1 <<endl;
	cout << "s2=" <<s2<<endl;
	int res = s1.compare(s2);	//= 返回 0 > 返回 1 < 返回 -1
	cout << res << endl;
}

void test03()
{
	cout << "7:字符存取操作"<<endl;
	string str = "hello world";
	cout << str <<endl;
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;


	//字符修改
	str[0] = 'x';
	str.at(1) = 'x';
	cout << str << endl;
}

//字符串插入和删除
void testdelete()
{
	cout << "8:字符插入删除"<<endl;
	string str = "hello";
	cout << str <<endl;
	str.insert(1, "000");
	cout << str <<endl;
	str.erase(1, 3);  //从1号位置开始3个字符
	cout << str << endl;
}


int main()
{
	test();
	test01();
	test02();
	test_find();
	test_replace();
	test_append();
	test_compare();
	test03();
	testdelete();
	return 0;
}