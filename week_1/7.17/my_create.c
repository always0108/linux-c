/*************************************************************************
	> File Name: my_create.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月17日 星期一 19时36分25秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>   //最后是L的小写，不是1
#include<unistd.h>
#include<errno.h>

int main(void)
{
    int fd;

    if((fd=open("example.c",O_CREAT|O_EXCL,S_IRUSR|S_IWUSR))==-1){
    //if((fd=creat("example.c",S_IRWXU))==-1){
        perror("open");
        printf("open:%s with errno:%d\n",strerror(errno),errno);
        exit(1);
    }
    else{
        printf("create file successfully!\n");
    }

    close(fd);
    return 0;
}
