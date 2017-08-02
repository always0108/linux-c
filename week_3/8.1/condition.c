/*************************************************************************
	> File Name: condition.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年08月01日 星期二 14时11分57秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t mutex;
pthread_cond_t cond;

void * thread1(void * arg)
{
    pthread_cleanup_push((void *)pthread_mutex_unlock,&mutex);
    while(1){
        printf("thread1 is running\n");
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond,&mutex);
        printf("thread1 applied the condition\n");
        pthread_mutex_unlock(&mutex);
        printf("unlock\n");
        printf("\n");
        sleep(1);
    }
    pthread_cleanup_pop(0);
}

void *thread2(void * arg)
{
    while(1){
        printf("thread2 is running\n");
        pthread_mutex_lock(&mutex);
        printf("thread2  get\n");
        pthread_cond_wait(&cond,&mutex);

        printf("thread2 applied the condition\n");
        
        pthread_mutex_unlock(&mutex);
        printf("unlock\n");
        printf("\n");
        sleep(1);
    }
}

int main(void)
{
    pthread_t tid1,tid2;

    printf("condition variable study!\n");
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);
    pthread_create(&tid1,NULL,(void *)thread1,NULL);
    pthread_create(&tid2,NULL,(void *)thread2,NULL);

    do{
        sleep(3);
        pthread_cond_signal(&cond);
    }while(1);
    sleep(50);
    pthread_exit(0);
}


/*
pthread_cleanup_push((void *)pthread_mutex_unlock, (void *) &mut);
pthread_mutex_lock(&mut);
// do some work 
pthread_mutex_unlock(&mut);
pthread_cleanup_pop(0);
本来do some work之后是有pthread_mutex_unlock(&mut);这句,也就是有解锁操作,但是在do some work时会出现非正常终止,那样的话,系统会根据pthread_cleanup_push中提供的函数,和参数进行解锁操作或者其他操作,以免造成死锁!
*/
