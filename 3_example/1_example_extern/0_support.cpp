// external.cpp -- external variables
// compile with support.cpp
#include <iostream>

using namespace std;

// external variables
double warming=0.3;

// function prototypes
void update(double dt);
void local();


int main()
{
    cout << "Global warming is " << warming << " degrees." <<endl;
    update(0.1);
    cout << "Global warming is " << warming << " degrees." <<endl;
    local();
    cout << "Global warming is " << warming << " degrees." <<endl;

    return 0;
}

