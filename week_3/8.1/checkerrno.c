/*************************************************************************
	> File Name: checkerrno.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年08月01日 星期二 15时18分37秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

int main()
{
    FILE *stream;
    char *filename = "test";

    errno=0;

    stream=fopen("filename","r");
    if(NULL == stream){
        printf("open file %s failed,errno is %d \n",filename,errno);
        perror("open failed");
    }
    else
        printf("open file %s sucessfully\n");

}

