#include <iostream>

using namespace std;

namespace KingGlory
{
	int sunwukongId=10;
}

namespace LOL
{
	int sunwukongId=100;
}

void test1()
{
	cout<<"test1: --------------"<<endl;
	int sunwukongId=20;
	cout<<"声明命名空间之前"<<endl;
	cout<<sunwukongId<<endl;

	//using声明， 注意避免二义性问题
	//写了using声明之后，下面这行代码说明以后的sunId就是用Kin空间下的sunid
	//但是，编译器又有就近原则，就会出现二义性
	// using KingGlory::sunwukongId;		//出现二义性冲突
	using namespace KingGlory;		//避免了二义性，但是仍然遵守就近原则

	cout<<"声明命名空间之后"<<endl;
	cout<<sunwukongId<<endl;
}

void test2()
{
	cout<<"test2: --------------"<<endl;
	int sunwukongId=30;
	cout<<"声明命名空间之前"<<endl;
	cout<<sunwukongId<<endl;

	//using 编译指令
	using namespace LOL;
	using namespace KingGlory;
	//打开多个namespace，需要避免二义性问题

	cout<<"LOL:"<<LOL::sunwukongId<<endl;
}


int main()
{
	test1();
	test2();
}