/*************************************************************************
	> File Name: my_rwl.c
	> Author: limeng
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年07月18日 星期二 09时08分55秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

//自定义的错误处理函数
void my_err(const char * err_string,int line)
{
    fprintf(stderr,"line:%d ",line);
    perror(err_string);
    exit(1);
}

//自定义读取数据函数
int my_read(int fd)
{
    int len;
    int ret;
    int i;
    char read_buf[64];

    //获取文件长度并保持文件读写指针在文件开始处
    if(lseek(fd,0,SEEK_END)==-1)
    {
        my_err("lseek",__LINE__);
    }
    if(len = lseek(fd,0,SEEK_CUR)==-1)
    {
        my_err("lseek",__LINE__);
    }
    if(lseek(fd,0,SEEK_SET)==-1)
    {
        my_err("lseek",__LINE__);
    }

    printf("len:%d\n",len);
    //读数据
    if((ret=read(fd,read_buf,len))<0)//这里读取文件数据
    {
        my_err("read",__LINE__);
    }

    //打印数据
    for(i=0;i<len;i++)    
    {
        printf("%c",read_buf[i]);
    }
    printf("\n");

    return ret;
}

int main(void)
{
    int fd;
    char write_buf[32]="hello world";

    //在当前目录下创建文件exampe_63.c
    if((fd=creat("exampe_63.c",S_IRWXU))==-1){
    //if((fd=open("exampe_64.c",O_RDWR|O_CREAT|O_TRUNC,S_IRWXU))==-1){
        my_err("open",__LINE__);   
    }
    else{
        printf("create file success\n");
    }

    //写数据
    if(write(fd,write_buf,strlen(write_buf))!=strlen(write_buf)){
        my_err("write",__LINE__);
    }
    
    //演示文件的间隔
    printf("-----------------------\n");
    if(lseek(fd,10,SEEK_END)==-1){
        my_err("lseek",__LINE__);
    }
    if(write(fd,write_buf,strlen(write_buf))!=strlen(write_buf)){
        my_err("write",__LINE__);
    }

    my_read(fd);
    close(fd);
    return 0;
}

/*create :
create file success
-----------------------
len:0
line:51 read: Bad file descriptor

open:
create file successi
-----------------------
len:0

新建的文件内容都是：
[limeng@localhost 7.18]$ od -c exampe_63.c
0000000   h   e   l   l   o       w   o   r   l   d  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0  \0   h   e   l   l   o       w   o   r   l   d
0000040

原因：

    creat("exampe_63.c",S_IRWXU))==-1)相当于
    open("exampe_63.c",O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU))==-1)//只可写，不可读，所以在读取时出现错误
    open("exampe_63.c",O_RDWR|O_CREAT|O_TRUNC,S_IRWXU))==-1)//可读可写
*/


