/*************************************************************************
	> File Name: fork3.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年07月25日 星期二 11时32分52秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(void)
{
    pid_t pid;
    int i;

    pid = fork();
    switch(pid){
        case 0:
            for(i=0;i<3;i++)
            {        
                sleep(2);
                printf("A backgroud process,PID:%d, ParentID %d\n",getpid(),getppid());
            }
            _exit(0);
        case -1:
            perror("process creation failed\n");
            exit(-1);
        default:
            printf("I am parent process,my pid is %d\n",getpid());
            exit(0);
    }
    return 0;
}


//inti 的PID不一定为1，本机1564相当于inti，可以收养孤儿进程
//[limeng@KID 7.25]$ A backgroud process,PID:7049, ParentID 1564
//A backgroud process,PID:7049, ParentID 1564
//A backgroud process,PID:7049, ParentID 1564



/*return会释放局部变量，并弹栈，回到上级函数执行。exit直接退掉。
 * 如果你用c++ 你就知道，return会调用局部对象的析构函数，exit不会。
 * （注：exit不是系统调用，是glibc对系统调用 _exit()或_exitgroup()的封装）。

_exit()函数的作用最为简单：直接使进程停止运行，清除其使用的内存空间，
并销毁其在内核中的各种数据结构；exit() 函数则在这些基础上作了一些包装，
在执行退出之前加了若干道工序。

exit()函数与_exit()函数最大的区别就在于exit()函数在调用exit系统调用之前
要检查文件的打开情况，把文件缓冲区中的内容写回文件，就是"清理I/O缓冲"。*/
