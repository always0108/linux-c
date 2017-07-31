/*************************************************************************
	> File Name: fcntl_access.c
	> Author: limeng
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年07月18日 星期二 15时47分40秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

//自定义处理错误函数
void my_err(const char * err_string,int line)
{
    fprintf(stderr,"line:%d ",line);
    perror("err_string");
    exit(1);
}

int main(void)
{
    int ret;
    int access_mode;
    int fd;

    if((fd=open("example64",O_CREAT|O_TRUNC|O_RDWR,S_IRWXU))==-1){
        my_err("open",__LINE__);
    }

    //设置文件打开方式
    if((ret=fcntl(fd,F_SETFL,O_APPEND))<0)
        my_err("fcntl",__LINE__);

    access_mode = ret & O_ACCMODE;

    if(access_mode==O_RDONLY){
        printf("example64 access_mode:read only");
    }
    else if(access_mode==O_WRONLY){
        printf("example64 access_mode:write only");
    }
      
    else if(access_mode==O_RDWR){
        printf("example64 access_mode:read + write");
    }

    if(ret & O_APPEND)
        printf(",append");

    if(ret & O_NONBLOCK)
        printf(",nonblock");
    if(ret & O_SYNC)
        printf(",sync");
    printf("\n");

    return 0;
}

