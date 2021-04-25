/*
Filename: const_1.cpp
Created by Zilch on 2020/4/26.
*/

#include "const_1.h"

void const_base() {
    //常量,不可修改，定义时必须初始化
    const int a  = 10;
//    const int a;  //错误；

}

void const_reference() {}

void const_pointer() {
    int errNumb = 0;
    int *const curErr = &errNumb;
}