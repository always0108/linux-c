/*************************************************************************
	> File Name: execve1.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年07月26日 星期三 10时39分46秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc,char ** argv,char **environ)
{
    pid_t pid;
    int stat_val;
    printf("Exec example!\n");
    pid = fork();
    switch(pid)
    {
        case -1:
            perror("Process creation failed\n");
            exit(1);
        case 0:
            printf("Child Process is running\n");
            printf("My pid = %d,parentpid = %d\n",getpid(),getppid());
            printf("uid = %d,gid = %d\n",getuid(),getgid());
            execve("processimage",argv,environ);
            printf("Process never go to there!\n");
            exit(0);
        default:
            printf("Parent process is running\n");
            break;
    }

    wait(&stat_val);
    exit(0);
}
