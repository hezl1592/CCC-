#include <iostream>
#include "3_class_1.h"

int main()
{
    Stock flu_cat("NanoSmart");
    flu_cat.show();

    flu_cat.acquire("newone", 20, 12.5);
    flu_cat.show();
    
    flu_cat.buy(15, 10);
    flu_cat.show();

    flu_cat.sell(15, 2);
    flu_cat.show();

    flu_cat.buy(30, 40);
    flu_cat.show();

    flu_cat.sell(20, 40);
    flu_cat.show();

    return 0;
}
