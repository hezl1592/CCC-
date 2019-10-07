#include <iostream>
#include "namesp.h"

void other();
void another();


int main()
{
    using debts::Debt;
    using debts::showDebt;

    Debt golf = {{"Benny", "Goatsniff"}, 120.0};
    showDebt(golf);
    other();
    another();

    return 0;
}

void other()
{
    using namespace std;
    using namespace debts;

    Person dg = {"Doodles", "Glister"};
    showPerson(dg);
    cout << endl;
    
    const int number = 2;
    Debt zippy [number];

    int i;
    for (i = 0; i<number; i++)
        getDebt(zippy[i]);
    for (i=0; i<number;i++)
        showDebt(zippy[i]);

    cout << "Total debt: $" << sumDebts(zippy, number) <<endl;
}

void another()
{
    using pers::Person;
    Person collector = {"Milo", "Rightshift"};
    pers::showPerson(collector);

    std::cout << std::endl;
}
