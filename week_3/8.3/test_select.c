/*************************************************************************
	> File Name: test_select.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年08月03日 星期四 15时56分26秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>
#include<time.h>

void display_time(const char *string)
{
    int seconds;

    seconds = time((time_t*)NULL);
    printf("%s, %d\n",string,seconds);
}

int main(void)
{
    fd_set    readfds;
    struct    timeval timeout;
    int       ret;

    //监视文件描述符0是否有数据输入，文件描述符0表示标准输入，即键盘输入*/
    //开始使用一个描述符前，一般要将其清空
    FD_ZERO(&readfds);
    FD_SET(0,&readfds);
    //timeout.tv_sec=10;
    //timeout.tv_usec=0;

    while(1)
    {
        
        timeout.tv_sec=10;
        timeout.tv_usec=0;//循环内对timeout初始化
        display_time("before select");
        ret = select(1,&readfds,NULL,NULL,&timeout);
        display_time("after select");

        switch(ret)
        {
            case 0:
                printf("No data in ten seconds\n");
                exit(0);
                break;
            case -1:
                perror("select");
                exit(1);
                break;
            default:
                getchar();
                printf("Data is available now.\n\n");
        }
    }
    return 0;
}
//timeout 要在循环中初始化，要不然第一次在5秒是按下enter键或者enter+任意键，
//select立即返回并打印出信息，再次设置select监听，这次阻塞时间只有5秒，如果
//case 0不调用exit(0),则从第三次开始不阻塞
