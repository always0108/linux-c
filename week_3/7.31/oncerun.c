/*************************************************************************
	> File Name: oncerun.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年07月31日 星期一 14时24分12秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void run(void)
{
    printf("Fuction run is running in thread %u\n",pthread_self());
}

void *thread1(void*arg)
{
    pthread_t thid = pthread_self();
    printf("Current thread's ID is %u\n",thid);
    pthread_once(&once,run);
    printf("thread1 ends\n");
}


void *thread2(void*arg)
{
    pthread_t thid = pthread_self();
    printf("Current thread's ID is %u\n",thid);
    pthread_once(&once,run);
    printf("thread2 ends\n");
}

int main(void)
{
    pthread_t thid1,thid2;

    pthread_create(&thid1,NULL,thread1,NULL);
    pthread_create(&thid2,NULL,thread2,NULL);
    sleep(3);
    printf("main thread exit! \n");
    exit(0);
}
