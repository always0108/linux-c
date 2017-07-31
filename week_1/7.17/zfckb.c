/*************************************************************************
	> File Name: zfckb.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月17日 星期一 14时52分48秒
 ************************************************************************/
//字符串拷贝
#include<stdio.h>

void copy_string1(char src[],char dst[])
{
    int i;
    for(i=0;src[i]!='\0';i++)
        dst[i]=src[i];
    dst[i]='\0';
}

void copy_string2(char *psrc,char *pdst)
{
    for(;*psrc != '\0';psrc++,pdst++)
        *pdst=*psrc;
    *pdst='\0';
}

int main(void)
{
    char a[]="xiyoulinuxgroup",b[20],c[20];

    copy_string1(a,b);
    copy_string2(a,c);

    printf("%s\n%s\n%s\n",a,b,c);
    return 0;
}

