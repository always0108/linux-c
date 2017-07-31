/*************************************************************************
	> File Name: test.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年07月27日 星期四 08时50分57秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

static char *line_read = (char *)NULL;

char *rl_gets()
{
    if(line_read)
    {       
        free (line_read);
        line_read = (char *)NULL;
    }
    line_read = readline("Please Enter:");
    if(line_read && *line_read)
        add_history(line_read);
     return(line_read);
}

int main()
{ 
    char *mline;
    int i;
    for(i=0;i<5;i++){
        mline = rl_gets();
        printf("%s\n",mline);
    }
    return 0;
}
