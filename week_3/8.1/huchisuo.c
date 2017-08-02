/*************************************************************************
	> File Name: huchisuo.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年08月01日 星期二 11时08分21秒
 ************************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex; //互斥锁

// 打印机,一段时间内只能被一个用户使用，不能被多人同时使用
void printer(char *str)
{
    pthread_mutex_lock(&mutex); //上锁
    while(*str!='\0')
    {
        putchar(*str);
        fflush(stdout);
        str++;
        sleep(1);
    }
    printf("\n");
    pthread_mutex_unlock(&mutex); //解锁
}


void printer2(char *str)
{
    //pthread_mutex_lock(&mutex); //上锁
    while(*str!='\0')
    {
        putchar(*str);
        fflush(stdout);
        str++;
        sleep(1);
    }
    printf("\n");
    //pthread_mutex_unlock(&mutex); //解锁
}
// 线程一
void *thread_fun_1(void *arg)
{
    char *str = "hello";
    printer(str); //打印
}

// 线程二
void *thread_fun_2(void *arg)
{
    char *str = "world";
    printer(str);
    //printer2(str); //打印
}

int main(void)
{
    pthread_t tid1, tid2;

    pthread_mutex_init(&mutex, NULL); //初始化互斥锁

    // 创建 2 个线程
    pthread_create(&tid1, NULL, thread_fun_1, NULL);
    pthread_create(&tid2, NULL, thread_fun_2, NULL);

    // 等待线程结束，回收其资源
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_mutex_destroy(&mutex); //销毁互斥锁

    return 0;
}

/*
 * 上锁
[limeng@KID 8.1]$ gcc huchisuo.c  -lpthread
[limeng@KID 8.1]$ ./a.out 
hello
world
 *不上锁 
[limeng@KID 8.1]$ gcc huchisuo.c  -lpthread
[limeng@KID 8.1]$ ./a.out 
hweolrlldi
thread1上锁，thread2不上锁
[limeng@KID 8.1]$ ./a.out
hweolrllod
*/
