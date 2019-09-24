#include <iostream>

int main()
{
    using namespace std;
    int rats = 101;
    int & rodents = rats;
    int *pt = &rats;

    cout << "rats = "<<rats;
    cout << ", rodents = "<<rodents;
    cout << ", *pt = "<<*pt<<endl;
    rodents++;
    cout << "rats = "<<rats;
    cout << ", rodents = "<<rodents;
    cout << ", *pt = "<<*pt<<endl;
    
    cout << "rats address =    " <<&rats<<endl;
    cout << "rodents address = "<<&rodents<<endl;
    cout << "*pt address =     "<<pt<<endl;
    return 0;
}

