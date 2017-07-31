/*************************************************************************
	> File Name: my_mv.c
	> Author: limeng
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年07月19日 星期三 11时02分21秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc,char ** argv)
{
    //先检查参数个数的合法性
    if(argc<3){
        printf("my_mv <oldfile> <newfile>\n");
        exit(0);
    }

    if(rename(argv[1],argv[2])<0){
        perror("rename");
        exit(1);
    }
    
    return 0;
}
