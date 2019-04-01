#include <iostream>

using namespace std;

void test_for(), test_while(), test_while1(), test_do_while();

int main()
{
	test_for();
	test_while();
	test_while1();
	test_do_while();

	return 0;
}

void test_for(){
	int sum=0;
	cout<<"test for loop: "<<endl;
	// for（）中的三个条件，可以空缺，但是必须在其他位置声明；
	for(int i=1; i<=100; )
	{
		sum += i++;
	}
	cout<<"sum="<<sum<<endl;
	cout<<"---------------------"<<endl;
}


void test_while(){
	int sum=0;
	int i=1;
	cout<<"test while loop: "<<endl;
	while(i<=100){
		sum += i;
		i++;
	}
	cout<<"sum="<<sum<<endl;
	cout<<"---------------------"<<endl;
}


void test_while1(){
	int sum=0;
	int i=1;
	cout<<"test while loop1: "<<endl;
	while(true){
		sum += i;
		if(i==100) break;
		i +=1; 
	}
	cout<<"sum="<<sum<<endl;
	cout<<"---------------------"<<endl;
}

// 不常用
void test_do_while(){
	int sum=0;
	int i=1;
	cout<<"test do while loop: "<<endl;
	do{
		sum += i;
		i += 1;
	}while(i<=100);
	cout<<"sum="<<sum<<endl;
	cout<<"---------------------"<<endl;
}