/*************************************************************************
	> File Name: unlink_temp.c
	> Author: limeng
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年07月19日 星期三 11时50分36秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

void my_err(const char *err_string,int line)
{
    fprintf(stderr,"line:%d",line);
    perror(err_string);
    exit(1);
}

int main(void)
{
    int fd;
    char buf[32];
    
    //创建
    if((fd = open("temp",O_RDWR|O_CREAT|O_TRUNC,S_IRWXU))<0){
        my_err("open",__LINE__);
    }
    //删除
    if(unlink("temp")<0){
        my_err("unlink",__LINE__);
    }//此时有进程打开这个文件，文件暂时不删除，知道这个进程(即该程序)结束后，文件才被删除
    printf("file unlinked\n");

    if(write(fd,"temp",5)<0){
        my_err("write",__LINE__);
    }
    if(lseek(fd,0,SEEK_SET)==-1){
        my_err("lseek",__LINE__);
    }
    if(read(fd,buf,5)<0){//文件仍然存在，所以可以对其进行读写操作
        my_err("read",__LINE__);
    }
    printf("%s\n",buf);

    return 0;
}

//程序结束后，文件会被删除

