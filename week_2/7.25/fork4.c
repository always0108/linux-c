/*************************************************************************
	> File Name: fork4.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年07月25日 星期二 14时53分14秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#include<sys/types.h>
int main(void)
{
    pid_t pid;
    pid = fork(  );
    switch(pid)
    {
        case 0:
        printf("fdsfsf");
        _exit(0); //退出什么也不做
        default:
        printf("fdssf");
        exit(0);  //退出要强制刷新缓冲区
    }

    return 0;
}
