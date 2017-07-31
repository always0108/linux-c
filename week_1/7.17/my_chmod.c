/*************************************************************************
	> File Name: my_chmod.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月17日 星期一 15时53分40秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

/*
    argc  整数,用来统计你运行程序时送给的命令行参数的个数

　  * argv: 字符串，用来存放指向你的字符串参数的，每一个元素指向一个参数

　　argv[0] 指向程序运行的全路径名

　　argv[1] 指向在DOS命令行中执行程序名后的第一个字符串

　　argv[2] 指向执行程序名后的第二个字符串

    int main(int argc,char **argv) 相当于 int main(int argc,char *argv[ ] )
*/
int main(int argc,char ** argv)
{
    int mode;    //权限
    int mode_u;
    int mode_g;
    int mode_o;
    char *path;

    //检查参数个数的合法性
    if(argc<3)
    {
        printf("%s <mode num><target file>\n",argv[0]);
        exit(0);
    }

    //获取命令行参数
    mode = atoi(argv[1]);    //将字符串转化为整数
    if(mode>777||mode<0){
        printf("mode num error!\n");
        exit(0);
    }

    mode_u=mode/100;
    mode_g=(mode-(mode_u*100))/10;
    mode_o=mode-(mode_u*100)-(mode_g*10);
    mode = (mode_u*8*8)+(mode_g*8)+mode_o;//转换为8进制
    path=argv[2];

    if(chmod(path,mode)==-1)//int chmod(const char *path,mode_t mode)
    {                       //若转换失败，则返回值为-1
        perror("chmod error");
        exit(1);
    }

    return 0;
}
