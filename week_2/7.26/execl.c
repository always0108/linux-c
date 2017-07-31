/*************************************************************************
	> File Name: execl.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年07月26日 星期三 10时06分05秒
 ************************************************************************/
//execl.c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
    if(fork()==0)
    {
        //调用execl()函数，注意这里要给出ps程序所在的完整路径
        if(execl("/bin/ps","ps","-ef",NULL)<0)
        {
            printf("Execl error\n");
        }
    }
}
