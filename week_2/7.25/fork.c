/*************************************************************************
	> File Name: fork.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年07月25日 星期二 10时44分15秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(void)
{
    pid_t pid;

    //printf("fork");
    printf("fork\n");
    pid = fork();
    switch(pid)
    {
        case 0:
            printf("Child process is running,CurPid is %d,ParentPid is %d\n",pid,getppid());
            break;
        case -1:
            perror("Process creation failed\n");
            break;
        default:
            printf("Parent process is running,ChildPid is %d,ParentPid is %d\n",pid,getpid());
            break;
    }
    exit(0);
    return 0;
}

//本机运行结果：
/*
   [limeng@KID linux-c]$ gcc fork.c
   [limeng@KID linux-c]$ ./a.out 
   Process creation study:
   Parent process is running,ChildPid is 6922,ParentPid is 6921
   Child process is running,CurPid is 0,ParentPid is 6921
*/


//书上的样例该有的输出：
/*
Process creation study:
Child process is running,CurPid is 0,ParentPid is 6921
Parent process is running,ChildPid is 6922,ParentPid is 6921
*/

//进程创建成功后，fork返回了两次，一次返回值是0，代表子进程在运行，通过
//getppid()得到父进程为6921；另外一次返回值为6922，是子进程的ID，用getpid()
//得到父进程的ID，与前面一致。switch执行两次，一次在子进程，一次在父进程

//本机的结果是父进程先运行，书上是子进程先运行。其实，fork之后的两个进程的先后
//顺序是不确定的，可以稍微修改来使两者交替。因为操作系统一般让所有进程都享有相同
//的执行权，除非某个进程的优先级比其他的高。


/*这里我在printf（"fork！"）这一行的fork！后面添加了一个换行符，变成printf（"fork！\n"）
 * 执行以后发现只打印一个fork！这个到底是什么原因呢？
主要的区别是因为有了一个\n回车符号，说起真正的原因，这和printf的缓冲机制有关了，
printf某些内容时，操作系统仅仅是把该内容放到了stdout的缓冲队列里了，并没有实际的写到屏幕上，
但是只要看到有\n 则会立即刷新stdout，因此就马上能够打印了。

还没有执行到fork（）的时候，原进程运行了printf（"fork！"）后，fork！仅仅被放到了缓冲里，
执行了fork，这时候子进程复制一份父进程的数据，包括这个stdout缓冲，在子进程度stdout缓冲
里面就也有了fork！。执行到后面这两个缓冲都打印到屏幕上，所以出现两次，并不是printf执行两次。
而运行printf（"fork！\n"）后，fork！被立即打印到了屏幕上，之后fork到的子进程里的stdout缓冲
里不会有fork！内容，因此你看到的结果会是fork！被printf了1次！！！*/
