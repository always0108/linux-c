/*************************************************************************
	> File Name: execve.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年07月26日 星期三 10时23分52秒
 ************************************************************************/
//execve.c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
    //命令参数列表，必须以NULL结尾
    char *arg[]={"env",NULL};//构造数组
    char *envp[]={"PATH=/tmp","USER=limeng",NULL};
    
    if(fork()==0)
    {
        if(execve("/usr/bin/env",arg,envp)<0)
        {
            printf("execle error\n");
        }
    }

}
