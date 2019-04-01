#include <iostream>

using namespace std;

void test_switch(), test_if();

int main(){
	test_switch();
	test_if();
}


void test_switch(){
	cout<<"test switch: "<<endl;
	char condition='优';
	switch(condition){
		case '优': cout<<"90---100"<<endl; break;
		case 'B': cout<<"80---90"<<endl; break;
		case 'C': cout<<"70---80"<<endl; break;
		case 'D': cout<<"60---70"<<endl; break;
		case 'E': cout<<"< 60"<<endl; break;
		default: cout<<"error\n";
	}
	cout<<"------------------"<<endl;
}


void test_if(){
	cout<<"test if: "<<endl;
	int a=12, b=20;		//定义整型数据a,b
	cout<<"a="<<a<<",b="<<b<<endl;
	cout<<"whose result is biger:"<<endl;
	if(a>b) cout<<a<<endl;
	else cout<<b<<endl;
	cout<<"----------------"<<endl;
}