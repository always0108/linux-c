/*************************************************************************
	> File Name: test_umask.c
	> Author: limeng
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年07月19日 星期三 10时48分44秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(void)
{
    umask(0);     //不屏蔽任何权限
    if(creat("example_681.test",S_IRWXU|S_IRWXG|S_IRWXO)<0){
        perror("creat");
        exit(1);
    }

    umask(S_IRWXO);  //屏蔽其他人的权限
    if(creat("example_682.test",S_IRWXU|S_IRWXG|S_IRWXO)<0){
        perror("creat");
        exit(1);
    }

    return 0;
}



/*生成两个文件的权限如下
-rwxrwxrwx 1 limeng limeng    0 7月  19 10:57 example_681.test
-rwxrwx--- 1 limeng limeng    0 7月  19 10:57 example_682.test
*/
