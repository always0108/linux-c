/*************************************************************************
	> File Name: execle.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年07月26日 星期三 10时16分08秒
 ************************************************************************/
//execle.c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
    //命令参数列表，必须以NULL结尾
    char *envp[]={"PATH=/tmp","USER=limeng",NULL};
    if(fork()==0)
    {
        //调用execle()函数，注意这里也要指出env的完整路径
        if(execle("/usr/bin/env","env",NULL,envp)<0)
        {
            printf("execle error\n");
        }
    }

}
