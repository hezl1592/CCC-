/*
Filename: template_func.h
Created by Zilch on 2020/4/19.
*/

#ifndef INC_8_TEMPLATE_TEMPLATE_FUNC_H
#define INC_8_TEMPLATE_TEMPLATE_FUNC_H

#include <iostream>
#include <cstring>

template<typename T>
void Swap(T &a, T &b);

template<typename T>
void Swap(T *a, T *b, int n);

template<typename T>
void show(T *a);

template<unsigned M, unsigned N>
int compare(const char (&a)[M], const char (&b)[N]);

//测试函数
void test_template_func();

void test_template_func_Overloading();

void test_1();
#endif //INC_8_TEMPLATE_TEMPLATE_FUNC_H
