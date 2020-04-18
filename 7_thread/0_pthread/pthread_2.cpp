/*
Filename: 1.cpp
Created by Zilch on 2020/4/18.
*/
#include "pthread.h"
#include <unistd.h>
#include <cstdio>

void *thr_fn1(void *arg) {
    printf("thread 1 returning\n");
    return (void *) 1;
}

void *thr_fn2(void *arg) {
    printf("thread 2 exiting\n");
    pthread_exit((void *) 2);
}

void *thr_fn3(void *arg) {
    while (true) {
        printf("thread 3 writing\n");
        sleep(1);
    }
}

int main() {
    pthread_t tid;
    void *tret;
//    1
    pthread_create(&tid, NULL, thr_fn1, NULL);
    pthread_join(tid, &tret);
    printf("thread 1 exit code %d\n", (int *) tret);

//    2
    pthread_create(&tid, NULL, thr_fn2, NULL);
    pthread_join(tid, &tret);
    printf("thread 2 exit code %d\n", (int *) tret);

//    3
    pthread_create(&tid, NULL, thr_fn3, NULL);
    sleep(3);
    pthread_cancel(tid);
    pthread_join(tid, &tret);
    printf("thread 3 exit code %d\n", (int *) tret);

    return 0;
}