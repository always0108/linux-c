/*************************************************************************
	> File Name: my_recv.h
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年08月04日 星期五 14时08分35秒
 ************************************************************************/

#ifndef _MY_RECV_H
#define _MY_RECV_H
    #define BUFSIZE 1024
    void my_err(const char * err_string,int line);
    int my_recv(int conn_fd,char *data_buf,int len);
#endif
