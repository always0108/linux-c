/*************************************************************************
	> File Name: jointhread.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年07月31日 星期一 15时19分50秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void assisthread(void *arg)
{
    printf("I am helping to do some jobs\n");
    sleep(2);
    printf("assisthread ends\n");
    pthread_exit(0);
}

int main(void)
{
    pthread_t assisthid;
    int status=2;

    pthread_create(&assisthid,NULL,(void *)assisthread,NULL);
    
    //pthread_join(assisthid,(void *)&status);
    
    //如果不用pthread_join将主线程挂起，并且不用pthread_exit()来退出主线程，
    //那么会直接结束该进程，不会管其它线程是否结束
    //pthread_exit()仅仅是主线程消亡，等到进程中的其它线程都结束时，进程才会结束
    printf("assisthread's exit is caused %d\n",status);

    //return 0;
    pthread_exit(0);
}
