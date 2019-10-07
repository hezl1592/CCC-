#include <iostream>

extern const int test_const;
int main()
{
    std::cout << test_const << std::endl;
    return 0;
}

