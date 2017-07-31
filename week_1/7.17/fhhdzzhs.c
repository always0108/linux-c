/*************************************************************************
	> File Name: fhhdzzhs.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月17日 星期一 14时37分15秒
 ************************************************************************/

//返回函数指针的函数
#include<stdio.h>

int get_big(int i,int j)
{
    return i>j?i:j;
}

int (*get_function(int a))(int,int)
{
    printf("the number is %d\n",a);

    return get_big;
}

int main(void)
{
    int i=5,j=10,max;

    int (*p)(int,int);
    p=get_function(50);

    max=p(i,j);
    printf("The max is %d\n",max);

    return 0;

}

