/*
Filename: template_func.cpp
Created by Zilch on 2020/4/19.
*/

#include "template_func.h"

using std::cout;
using std::endl;

template<typename T>
void Swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void Swap(T a[], T b[], int n) {
    T temp;
    for (int i = 0; i < n; i++) {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

template<typename T>
void show(T a[]) {
    for (int i = 0; i < 6; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void test_template_func() {
    int i = 10;
    int j = 100;
    cout << "int:\n";
    cout << "i = " << i << ",j = " << j << endl;
    Swap(i, j);
    cout << "after swap:\n";
    cout << "i = " << i << ",j = " << j << endl;
    cout << "----------------------------------------" << endl;

    double m = 12.8;
    double n = 120.9;
    cout << "double:\n";
    cout << "m = " << m << ",n = " << n << endl;
    Swap(m, n);
    cout << "after swap:\n";
    cout << "m = " << m << ",n = " << n << endl;
    cout << "----------------------------------------" << endl;
}

void test_template_func_Overloading() {
    int a[] = {0, 1, 2, 3, 4, 5};
    int b[] = {5, 4, 3, 2, 1, 0};

    cout << "a: ";
    show(a);
    cout << "b: ";
    show(b);
    Swap(a, b, 6);

    cout << "after:\n";
    cout << "a: ";
    show(a);
    cout << "b: ";
    show(b);
    cout << "----------------------------------------" << endl;
}