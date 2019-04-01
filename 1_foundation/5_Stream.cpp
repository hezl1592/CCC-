#include <iostream>

using namespace std;

void test();

int main()
{
	test();
}

void test(){
	cout<<"cout stream:"<<endl;
	cout<<"---------------------"<<endl;
	// cout<<12<<" showpos ";
	// cout<<showpos<<12<<endl;
	cout<<18<<" hex ";
	cout<<hex<<18<<showbase<<18<<endl;
}