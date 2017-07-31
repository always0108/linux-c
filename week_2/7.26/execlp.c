/*************************************************************************
	> File Name: execlp.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年07月26日 星期三 10时00分06秒
 ************************************************************************/
//exceclp.c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
    int ret ;
    if(fork()==0)//在新建的子进程中执行新的程序
    {
        /*调用exceclp()函数，在这里相当于调用了"ps -ef"命令*/
        if((ret=execlp("ps","ps","-ef",NULL)<0))
             perror("execlp error\n");
    }
}
