/*
Filename: template_1.cpp
Created by Zilch on 2020/4/19.
*/
#include "template_func.h"
#include "stack_template.hpp"
#include <iostream>
#include <cstdlib>      //for rand() srand()
#include <ctime>        //for time()

using namespace std;


const int NUM = 10;

void test_class_template();

int main() {
    test_template_func();
    test_template_func_Overloading();
    test_1();
    cout << endl << "------------------------------------------" << endl;
    test_class_template();
    return 0;
}

void test_class_template() {
    std::srand(std::time(0)); // randomize rand()
//    std::cout << "Please enter stack size: ";
    int stacksize = 5;
//    std::cin >> stacksize;
// create an empty stack with stacksize slots
    Stack<const char *> st(stacksize);

// in basket
    const char *in[NUM] = {
            " 1: Hank Gilgamesh", " 2: Kiki Ishtar",
            " 3: Betty Rocker", " 4: Ian Flagranti",
            " 5: Wolfgang Kibble", " 6: Portia Koop",
            " 7: Joy Almondo", " 8: Xaverie Paprika",
            " 9: Juan Moore", "10: Misha Mache"
    };
    // out basket
    const char *out[NUM];

    int processed = 0;
    int nextin = 0;
    while (processed < NUM) {
        if (st.isempty())
            st.push(in[nextin++]);
        else if (st.isfull())
            st.pop(out[processed++]);
        else if (std::rand() % 2 && nextin < NUM)   // 50-50 chance
            st.push(in[nextin++]);
        else
            st.pop(out[processed++]);
    }
    for (int i = 0; i < NUM; i++)
        std::cout << out[i] << std::endl;

    std::cout << "Bye\n";
}