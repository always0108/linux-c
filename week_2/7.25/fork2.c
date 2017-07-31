/*************************************************************************
	> File Name: fork2.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年07月25日 星期二 11时14分06秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

//父子进程可以交替执行
int main(void)
{
    pid_t pid;
    char * msg;
    int k;

    printf("Process creation study:\n");
    pid = fork();
    switch(pid)
    {
        case 0:
            msg = "Child process is running";
            k=3;
            break;
        case -1:
            perror("Process creation failed\n");
            break;
        default:
            msg = "Parent process is running";
            k=5;
            break;
    }

    while(k>0)
    {
        puts(msg);
        sleep(1);
        k--;
    }
    exit(0);
    return 0;

}
