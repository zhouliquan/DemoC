#include <stdio.h>
#include <pthread.h>
//编译命令gcc demoThread.c -lpthread

void thread()
{
    int i;
    for(i = 0; i < 20; i++) {
        printf("This is a pthread.\n");
    }
}

int main(void)
{
    //声明变量
    pthread_t id;
    int i, ret;

    //创建线程
    ret = pthread_create(&id, NULL, (void*)thread, NULL);
    if(ret != 0) {
        printf("Create pthread error!\n");
        exit(1);
    }

    for(i = 0; i < 20; i++) {
        printf("This is the main process.\n");
    }

    //等待线程结束
    pthread_join(id, NULL);

    return 0;
}
