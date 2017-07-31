/*************************************************************************
	> File Name: studyuid.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年07月26日 星期三 14时13分24秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>

extern int errno;

int main(void)
{
    int fd;

    printf("uid study:\n");
    printf("Process's uid = %d,euid = %d\n",getuid(),geteuid());

    //strerror函数获取指定错误代码的提示信息
    if((fd = open("test.c",O_RDWR)) == -1){
        printf("open fail,errno is %d :%s \n ",errno,strerror(errno));
        exit(1);
    }
    else{
        printf("open successfully!\n");
    }

    close(fd);
    exit(0);
}

//SUID 权限仅对二进制程序有效，执行者对于该程序要有x的可执行权限，本权限仅在
//执行该程序的过程中有效，执行者将具有该程序所有者的权限

//如果该程序的所有者不是root，即使加上SUID，执行该程序的用户也不会有root的权限


/*
[root@KID 7.26]# gcc studyuid.c -o studyuid
[root@KID 7.26]# ./studyuid 
uid study:
Process's uid = 0,euid = 0
open successfully!
[root@KID 7.26]# exit
exit
[limeng@KID 7.26]$ ./studyuid 
uid study:
Process's uid = 1000,euid = 1000
open fail,errno is 13 :Permission denied 
 [limeng@KID 7.26]$ su
密码：
[root@KID 7.26]# chmod 4755 studyuid
[root@KID 7.26]# ./studyuid 
uid study:
Process's uid = 0,euid = 0
open successfully!
[root@KID 7.26]# exit
exit
[limeng@KID 7.26]$ ./studyuid 
uid study:
Process's uid = 1000,euid = 0
open successfully!
*/
