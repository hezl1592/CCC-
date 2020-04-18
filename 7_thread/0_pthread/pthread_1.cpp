#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

//线程标识符
pthread_t ntid;

//打印当前线程的id以及当前进程的pid
void printids(const char *s) {
    pid_t pid;
    pthread_t tid;
    pid = getpid();//获取进程pid号
    tid = pthread_self();   //获取线程id
//    printf("%d\n", ntid);
    printf("%s pid %u tid %u (0x%x)\n", s, (unsigned int) pid, (unsigned int) tid, (unsigned int) tid);
}

//定义
void *thr_fn(void *arg) {
    printids((char *) arg);
    return NULL;
}

int main(void) {
    int err;
//    创建线程
    err = pthread_create(&ntid, NULL, thr_fn, (char *) "new thread: ");
    if (err != 0) {
        fprintf(stderr, "can't create thread: %s\n", strerror(err));
        exit(1);
    }
    printids("main thread:");
    sleep(1);
    return 0;
}
