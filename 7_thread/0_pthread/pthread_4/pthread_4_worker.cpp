/*
Filename: pthread_4_worker.cpp
Created by Zilch on 2020/4/18.
*/
#include "pthread_4_worker.h"

const int NLOOP = 1000000;
int counter = 0;

//
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

void *worker(void *arg) {
    cout << "Thread start." << endl;
    int i;
    for (i = 0; i < NLOOP; i++) {
        counter += 1;
    }
    return NULL;
}

void *worker_mutex(void *arg) {
    cout << "Thread start." << endl;
    int i;
    for (i = 0; i < NLOOP; i++) {
        pthread_mutex_lock(&counter_mutex);     //当前线程设置锁，放置其他线程进行操作
        counter += 1;
        pthread_mutex_unlock(&counter_mutex);   //解锁
    }
    return NULL;
}

void test_without() {
    counter = 0;
    cout << "without:\n";
    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, worker, NULL);
    pthread_create(&tid2, NULL, worker, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    cout << "counter=" << counter << endl;
}

void test_with_mutex() {
    // 初始化
    counter = 0;
    cout << "With mutex." << endl;
    pthread_t tid1, tid2;

//mutex
    pthread_mutex_lock(&counter_mutex);
    cout << "mutex value:" << *(int *) counter_mutex << endl;
    pthread_mutex_unlock(&counter_mutex);
    cout << "mutex value:" << *(int *) counter_mutex << endl;

    pthread_create(&tid1, NULL, worker_mutex, NULL);
    pthread_create(&tid2, NULL, worker_mutex, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    cout << "counter=" << counter << endl;
}