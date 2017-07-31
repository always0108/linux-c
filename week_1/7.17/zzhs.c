/*************************************************************************
	> File Name: zzhs.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月17日 星期一 14时01分27秒
 ************************************************************************/

//指针函数,返回指针的函数
#include<stdio.h>

char *Name[7] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

char *message = "wrong input";

char *week(int day)
{
    if(day<=0||day>7)
        return message;
    else
       return Name[day-1];
}

int main()
{
    int day;
    char *p;
    printf("Input a number of a week:\n");
    scanf("%d",&day);

    p = week(day);
    printf("%s\n",p);
    return 0;
}
