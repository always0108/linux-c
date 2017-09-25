/*************************************************************************
	> File Name: my_sigaction.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年09月25日 星期一 20时35分11秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

int temp = 0;

/*信号处理函数*/
void handler_sigint(int signo)
{
    printf("recv SIGINT\n");
    sleep(5);
    temp += 1;
    printf("the value of temp is: %d\n",temp);
    printf("in handler_sigint, after sleep\n");
}

int main(void)
{
    struct sigaction act;

    /*赋值act结构*/
    act.sa_handler = handler_sigint;
    act.sa_flags = SA_NOMASK;

    /*安装信号处理函数*/
    sigaction(SIGINT,&act,NULL);

    while(1)
        ;

    return 0;
}
