/*************************************************************************
	> File Name: processimage.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年07月26日 星期三 10时31分52秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc,char ** argv,char ** environ)
{
    int i;

    printf("I am a process image!\n");
    printf("My pid = %d,parentpid = %d\n",getpid(),getppid());
    printf("uid = %d,gid = %d\n",getuid(),getgid());

    for(i=0; i < argc;i++)
        printf("argv[%d]:%s\n",i,argv[i]);
    return 0;
}
