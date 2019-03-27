#include <iostream>

// using namespace std;

int avar=10; //全局变量avar
void test();

int main(){
	int avar=25; //局部变量avar

	std::cout<<"local avar: "<<avar<<std::endl;
	std::cout<<"global avar: "<<::avar<<std::endl;

	// ::作用域运算符
	::avar=80; //重置全局变量
	std::cout<<"local avar: "<<avar<<std::endl;
	std::cout<<"global avar: "<<::avar<<std::endl;
	std::cout<<"--------"<<std::endl;

	test();
	return 0;
}

void test(){
	std::cout<<"test: global avar: "<<::avar<<std::endl;
}