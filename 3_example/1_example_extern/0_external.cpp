// support.cpp -- use external variables
// compile with external.cpp
#include <iostream>

extern double warming;

using namespace std;

void update(double dt)
{
    extern double warming;
    warming += dt;

    cout << "Updating global warming to " << warming;
    cout << " degrees." <<endl;

}

void local()
{
    double warming = 0.8;

    cout << "Local warming = "<<warming<<" degrees.\n";
    // ::warming表示使用该变量的全局版本
    cout << "But global warming = " << ::warming;
    cout << " degrees.\n";
}
