#include <stdio.h>
#include <pthread.h>

int buf = 0;
// 声明互斥锁
pthread_mutex_t mutex;

void thread_func1()
{
    while(buf < 30) {
        // 加锁
        pthread_mutex_lock(&mutex);
        buf++;
        printf("thread1:%d\n", buf);
        sleep(5);
        // 解锁
        pthread_mutex_unlock(&mutex);
        sleep(2);
    }
}

void thread_func2()
{
    while(buf < 30) {
        pthread_mutex_lock(&mutex);
        buf++;
        printf("thread2:%d\n", buf);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void main(void)
{
    pthread_t thread1, thread2;
    int ret1, ret2;

    //初始化mutex
    pthread_mutex_init(&mutex, NULL);
    ret1 = pthread_create(&thread1, NULL, (void*)thread_func1, NULL);
    if(ret1 != 0 ){
        printf("Create Thread1 faild\n");
        return 1;
    } 
    
    ret2 = pthread_create(&thread2, NULL, (void*)thread_func2, NULL);
    if(ret2 != 0 ){
        printf("Create Thread2 faild\n");
        return 2;
    }
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
}
