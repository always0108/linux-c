/*************************************************************************
	> File Name: env.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年07月26日 星期三 08时15分56秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>

//extern char **environ;   //预定义全局变量

//main函数的完整形式
int main(int argc,char ** argv,char ** envp)
{
    int i;

    printf("Argument:\n");
    for(i=0;i<argc;i++)
    {
        printf("argv[%d] is %s\n",i,argv[i]);
    }
    printf("Environment");

    // for(i=0;environ[i]!=NULL;i++)
    //   printf("%s\n",environ[i]);
    
    for(i=0;envp[i]!=NULL;i++)
        printf("%s\n",envp[i]);

    return 0;
}

