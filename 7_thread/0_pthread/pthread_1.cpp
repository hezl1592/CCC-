#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

//�̱߳�ʶ��
pthread_t ntid;

//��ӡ��ǰ�̵߳�id�Լ���ǰ���̵�pid
void printids(const char *s) {
    pid_t pid;
    pthread_t tid;
    pid = getpid();//��ȡ����pid��
    tid = pthread_self();   //��ȡ�߳�id
//    printf("%d\n", ntid);
    printf("%s pid %u tid %u (0x%x)\n", s, (unsigned int) pid, (unsigned int) tid, (unsigned int) tid);
}

//����
void *thr_fn(void *arg) {
    printids((char *) arg);
    return NULL;
}

int main(void) {
    int err;
//    �����߳�
    err = pthread_create(&ntid, NULL, thr_fn, (char *) "new thread: ");
    if (err != 0) {
        fprintf(stderr, "can't create thread: %s\n", strerror(err));
        exit(1);
    }
    printids("main thread:");
    sleep(1);
    return 0;
}
