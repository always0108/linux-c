/*************************************************************************
	> File Name: my_signal.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年09月25日 星期一 19时14分04秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<signal.h>

/*信号处理函数*/
void hander_sigint(int signo){
    printf("recv SIGINT\n");
}

int main(void)
{
    /*安装信号处理函数*/
    signal(SIGINT,hander_sigint);

    while(1)
        ;

    return 0;
}


/*程序先用signal()安装信号SIGINT的处理函数handler_sigint,然后进入死循环。当接收到SIGINT信号时，
 *程序自动跳转到信号处理函数处执行，打印出提示信息，然后返回主函数继续死循环。
 *ctrl+\组合键向进程发送SIGQUIT信号结束进程*/
