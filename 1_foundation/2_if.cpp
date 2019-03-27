#include <iostream>

using namespace std;

void example1();
void example2();

int main(){
	example1();
	cout<<"--------------"<<endl;
	example2();
}

//
void example1(){
	int a=12, b=20;		//定义整型数据a,b
	cout<<"a="<<a<<",b="<<b<<endl;
	cout<<"whose result is biger:"<<endl;
	if(a>b) cout<<a<<endl;
	else cout<<b<<endl;
}

void example2(){
	int a=20, b=35,c=67;
	cout<<"a="<<a<<",b="<<b<<",c="<<c<<endl;
	cout<<"whose result is biger:"<<endl;
	if(a>b){
		if(a>c){
			if(b>c) cout<<"a>b>c"<<endl;
			else cout<<"a>c>b"<<endl;
		}
		else cout<<"c>a>b"<<endl;
	}
	else{
		if(b>c){
			if(a>c) cout<<"b>a>c"<<endl;
			else cout<<"b>c>a"<<endl;
		}
		else cout<<"c>b>a"<<endl;
	}
}