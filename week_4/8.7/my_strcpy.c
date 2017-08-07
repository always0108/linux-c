/*************************************************************************
	> File Name: my_strcpy.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年08月07日 星期一 14时08分13秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *my_strcpy(char *strDest ,const char *strSrc)
{
    char *p_return = strDest ;

    //检查参数指针是否为空
    if(strDest == NULL || strSrc == NULL){
        fprintf(stderr,"NULL pointer");
        return NULL;
    }

    while((*strDest++ = *strSrc++) != '\0')
        ;
    return p_return;
}

int main(void)
{
    char string1[32];
    char string2[32];
    char c;
    int i=0;

    printf("please input your string:");
    //对输入字符串的长度进行检查,判断是否为文件结束标识符，以及是否遇到了回车键，
    //同时还对输入字符的个数进行了检查
    while(((c = getchar()) != '\n') && (c != EOF) && (i < 31))
    //将&&(i<31)去掉后，若输入超过31个字符;或者将my_strcpy函数中对指针是否为NULL的判断去掉，
    //同时在main函数中定义一个char *p,调用my_strcpy(p,string2)。都会出现段错误。
    {
        string2[i] = c;
        i++;
    }
    string2[i] = '\0';

    //对返回值也进行合法性检查
    if (my_strcpy(string1,string2) == NULL){
        fprintf(stderr,"return from my_strcpy");
        exit(1);
    } 

    printf("string1:%s\n",string1);
    printf("string2:%s\n",string2);
    return 0;
}
