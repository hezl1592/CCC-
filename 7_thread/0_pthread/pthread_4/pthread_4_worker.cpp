/*
Filename: pthread_4_worker.cpp
Created by Zilch on 2020/4/18.
*/
#include "pthread_4_worker.h"

const int NLOOP = 1000000;
int counter = 0;

//声明互斥锁
pthread_mutex_t counter_mutex;

int count = 0;
pthread_mutex_t mutex_2;
pthread_cond_t cond;

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
//        cout << "consume thread mutex value= "<<*(int *)counter_mutex << endl;
        counter += 1;
        pthread_mutex_unlock(&counter_mutex);   //解锁
//        cout << "consume thread mutex value= "<<*(int *)counter_mutex << endl;
    }
    return NULL;
}

void *produce(void *args) {
    cout << "produce thread." << endl;
    while (true) {
        sleep(2);
        pthread_mutex_lock(&mutex_2);
        while (count > 10) {
            sleep(1);
            cout << "product too much, sleep 1 sec." << endl;
//            pthread_mutex_unlock(&mutex_2);
//            pthread_cond_signal(&cond);
//            continue;
        }
        ++count;
        cout << "product is " << pthread_self() << "\tcount= " << count << endl;
        pthread_mutex_unlock(&mutex_2);
        pthread_cond_signal(&cond);     //唤醒等待该条件变量上的某个线程（消费者）
    }
    pthread_exit(NULL);
}

void *consume(void *args) {
    cout << "consume thread." << endl;
    while (true) {
        sleep(1);
        pthread_mutex_lock(&mutex_2);
        while (count == 0) {
            cout << "consume thread mutex value= "<<*(int *)mutex_2 << endl;
            cout << "product too little, sleep 1 sec.\n";

            pthread_cond_wait(&cond, &mutex_2);
            cout << "consume thread mutex value= "<<*(int *)mutex_2 << endl;
//            pthread_mutex_unlock(&mutex_2);
//            continue;
        }
        --count;
        cout << "consumer is " << pthread_self() << "\tcount= " << count << endl;
        pthread_mutex_unlock(&mutex_2);
    }
    pthread_exit(NULL);
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

//     初始化
    pthread_mutex_init(&counter_mutex, NULL);

//mutex
    pthread_mutex_lock(&counter_mutex);
    cout << "mutex value:" << *(int *) counter_mutex << endl;
    pthread_mutex_unlock(&counter_mutex);
    cout << "mutex value:" << *(int *) counter_mutex << endl;

//    启动线程
    pthread_create(&tid1, NULL, worker_mutex, NULL);
    pthread_create(&tid2, NULL, worker_mutex, NULL);

//    等待线程
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

//    注销互斥锁
    int res = pthread_mutex_destroy(&counter_mutex);
    cout << res << endl;

    cout << "counter=" << counter << endl;
}

int test_with_condition() {
    cout << endl << "with condition.\n";
    pthread_mutex_init(&mutex_2, NULL);
    pthread_cond_init(&cond, NULL);
//    cout << *(int *)mutex_2 <<endl;

//    cout << res<<endl;

    pthread_t tid1;
    pthread_t tid2;

    int ret1 = pthread_create(&tid1, NULL, produce, NULL);
    sleep(1);
    int ret2 = pthread_create(&tid2, NULL, consume, NULL);
//    cout << ret1 <<ret2<<endl;
    if (ret1 || ret2) {
        cout << "thread created failed." << endl;
        return -1;
    }
    pthread_detach(tid1);
    pthread_detach(tid2);

    getchar();

    pthread_cond_destroy(&cond);
    return 0;
}