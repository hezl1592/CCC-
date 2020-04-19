/*
Filename: pthread_4_worker.h
Created by Zilch on 2020/4/18.
*/

#ifndef INC_0_CREATE_PTHREAD_4_WORKER_H
#define INC_0_CREATE_PTHREAD_4_WORKER_H

#include <iostream>
#include "pthread.h"
#include <unistd.h>

using std::cout;
using std::endl;

void *worker(void *arg);
void *worker_mutex(void *arg);
void* produce(void* args);
void* consume(void* args);



void test_without();
void test_with_mutex();
int test_with_condition();


#endif //INC_0_CREATE_PTHREAD_4_WORKER_H
