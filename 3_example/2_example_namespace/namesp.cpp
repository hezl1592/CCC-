#include <iostream>
#include "namesp.h"

namespace pers
{
    using std::cout;
    using std::cin;
    void getPerson(Person & rp)
    {
        cout << "Enter first name: ";
        cin >> rp.fname;
        cout << "Enter last name: ";
        cin >> rp.lname;
    }
    void showPerson(const Person & rp)
    {
        cout << rp.fname << ", "<<rp.lname;
    }
}

namespace debts
{
    void getDebt(Debt & rp)
    {
        getPerson(rp.name);
        std::cout << "Enter debt: ";
        std::cin >> rp.amount;
    }
    void showDebt(const Debt & rp)
    {
        showPerson(rp.name);
        std::cout << ": $" << rp.amount << std::endl;
    }
    double sumDebts(const Debt ar[], int n)
    {
        double total = 0;
        for (int i=0; i<n;i++)
            total += ar[i].amount;
        return total;
    }
}

