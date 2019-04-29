#include <climits>
#include <iostream>

using namespace std;

int main()
{	
	short a_max = SHRT_MAX;
	short a_max_1;
	short a_max_2;
	unsigned short b_max = USHRT_MAX;
	unsigned short b_max_1, b_max_2;
	cout<<"short data max value is: "<<a_max<<endl;

	a_max_1 = a_max + 1;
	a_max_2 = a_max + 2;
	cout<<"max + 1 = "<<a_max_1<<endl;
	cout<<"max + 2 = "<<a_max_2<<endl;
	
	cout<<"-----------------------------"<<endl;
	cout<<"unsigned short data max value is: "<<b_max<<endl;

	b_max_1 = b_max + 1;
	b_max_2 = b_max + 2;
	cout<<"max + 1 = "<<b_max_1<<endl;
	cout<<"max + 2 = "<<b_max_2<<endl;
	return 0;
}
