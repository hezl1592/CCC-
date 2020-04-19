/*
Filename: template_func.h
Created by Zilch on 2020/4/19.
*/

#ifndef INC_8_TEMPLATE_TEMPLATE_FUNC_H
#define INC_8_TEMPLATE_TEMPLATE_FUNC_H

#include <iostream>

template<typename T>
void Swap(T &a, T &b);

template<typename T>
void Swap(T *a, T *b, int n);

template<typename T>
void show(T *a);

//测试函数
void test_template_func();

void test_template_func_Overloading();

#endif //INC_8_TEMPLATE_TEMPLATE_FUNC_H
