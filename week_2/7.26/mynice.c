/*************************************************************************
	> File Name: mynice.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
    > Created Time: 2017年07月26日 星期三 15时34分42秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/resource.h>
#include<sys/wait.h>
#include<unistd.h>

int main(void)
{
    pid_t pid;
    int stat_val = 0;
    int oldpri,newpri;

    printf("nice study\n");

    pid = fork();
    switch(pid)
    {
        case 0:
            printf("Child is running, Curpid is %d, ParentPid is %d\n",pid,getppid());

            oldpri = getpriority(PRIO_PROCESS,0);
            printf("Old priority = %d\n",oldpri);

            newpri = nice(2);
            printf("New priority = %d\n",newpri);

            exit(0);

        case -1:
            perror("Process creation failed\n");
            break;
        default:
            printf("Parent is running ,ChildPid is %d, ParentPid is %d\n",pid,getpid());
            break;
    }

    wait(&stat_val);
    exit(0);
}

/*
[limeng@KID 7.26]$ gcc mynice.c 
[limeng@KID 7.26]$ ./a.out 
nice study
Parent is running ,ChildPid is 13979, ParentPid is 13978
Child is running, Curpid is 0, ParentPid is 13978
Old priority = 0
New priority = 2
*/
