#include<iostream>

using namespace std;

void sphere();

int main(){
	sphere();
}

void sphere(){
	double radius;
	cout<<"Please input radius: ";
	cin>>radius;
	if(radius<0) return;
	cout<<"The result is "<<radius*radius*3.14*4<<"\n";
}