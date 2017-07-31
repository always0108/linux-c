/*************************************************************************
	> File Name: wait.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年07月26日 星期三 11时15分09秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(void)
{
    pid_t pid;
    char *msg;
    int k;
    int exit_code;

    printf("Study how to get exit code\n");
    pid=fork();
    switch(pid)
    {
        case 0:
            msg = "Child process is running";
            k=5;
            exit_code = 37;
            break;
        case -1:
            perror("process creation failed\n");
            exit(1);
        default :
            exit_code = 0;
            break;
    }

    //父子进程都会执行以下的代码
    //子进程的pid值为0，父进程的pid为子进程的ID
    if(pid != 0)
    {
        int stat_val;
        pid_t child_pid;

        child_pid = wait(&stat_val);

        printf("Child process has exited,pid = %d\n",child_pid);

        if(WIFEXITED(stat_val))
            printf("Child exit with code %d\n",WEXITSTATUS(stat_val));
        else
            printf("Child exited abnormally");
    }
    else {
        while(k-->0){
            puts(msg);
            sleep(1);
        }
    }



}
