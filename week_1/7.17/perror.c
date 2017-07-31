/*************************************************************************
	> File Name: perror.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月17日 星期一 16时46分28秒
 ************************************************************************/

#include <stdio.h>

int main ()
{
   FILE *fp;

   /* 现在让我们尝试打开一个不存在的文件 */
   fp = fopen("file.txt", "r");
   if( fp == NULL ) {
      perror("Error: ");
      return(-1);
   }
   fclose(fp);
      
   return(0);
}

/*
C 库函数 void perror(const char *str) 把一个描述性错误消息输出到标准错误 stderr。首先输出字符串 str，后跟一个冒号，然后是一个空格。
str -- 这是 C 字符串，包含了一个自定义消息，将显示在原本的错误消息之前。
*/

/*输出结果:
        空格
 Error: : No such file or directory
 str   冒号       错误信息
*/
