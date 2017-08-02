/*************************************************************************
	> File Name: errshow.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年08月01日 星期二 15时24分44秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

FILE * open_file(char * filename)
{
    FILE *stream;
    errno = 0;

    stream = fopen(filename,"r");
    if(NULL == stream)
    {
        printf("can't open the file %s .reason: %s\n",filename,strerror(errno));
        exit(-1);
    }
    else
        return stream;
}

int main(void)
{
    char *filename = "test";

    open_file(filename);
    return 0;
}
