/*************************************************************************
	> File Name: test_address.c
	> Author:limeng 
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年08月03日 星期四 11时19分52秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(void)
{
    char    buffer[32];
    int     ret = 0;
    int     host = 0;
    int     network = 0;
    unsigned int address = 0;
    struct  in_addr in;

    in.s_addr = 0;

    /*输入一个以"."分隔的字符串形式的IP地址*/
    printf("please input your ip address:");
        fgets(buffer,31,stdin);
    buffer[31]='\0';

    /*使用inet_aton函数,将字符串形式的ip地址转化为二进制的网络字节顺序*/
    if((ret = inet_aton(buffer,&in))== 0)
        printf("inet_aton: \t invaild address\n");
    else
        printf("inet_aton: \t0x%lx\n",in.s_addr);

    /*使用inet_addr函数, 和inet_aton功能类似*/
    if((address = inet_addr(buffer) )== INADDR_NONE)
        printf("inet_addr:\t invaild address\n");
    else
        printf("inet_addr:\t 0x%lx\n",address);

    /*使用inet_network函数，将字符串形式的网络地址转换为主机字节序形式的二进制IP地址*/
    if((address = inet_network(buffer))==-1)
        printf("inet_network: \t invaild address\n");
    else 
        printf("inet_network:\t%lx\n",address);

    /* inet_ntoa()函数，将网络字节序形式的ip地址转化为"."分隔的字符串*/
    if(inet_ntoa(in) ==NULL)
        printf("inet_ntoa: \t invaild address\n");
    else
        printf("inet_ntoa: \t%s\n",inet_ntoa(in));

    /*inet_lnaof与inet_netof*/
    host = inet_lnaof(in);//获取主机号
    network = inet_netof(in);//获取网络号

    printf("inet_lnaof: \t%x\n",host);
    printf("inet_netof: \t%x\n",network);

    in = inet_makeaddr(network,host);//把网络号和主机号组合成一个网络地址
    printf("inet_makeaddr: 0x%x\n",in.s_addr);

    return 0;
}

/*
please input your ip address:192.168.1.1
inet_aton: 	0x101a8c0
inet_addr:	 0x101a8c0
inet_network:	c0a80101
inet_ntoa: 	192.168.1.1
inet_lnaof: 	1
inet_netof: 	c0a801
inet_makeaddr: 0x101a8c0

[limeng@KID 8.3]$ ./a.out 
please input your ip address:255.255.255.255
inet_aton: 	0xffffffff
inet_addr:	 invaild address
inet_network: 	 invaild address
inet_ntoa: 	255.255.255.255
inet_lnaof: 	ff
inet_netof: 	ffffff
inet_makeaddr: 0xffffffff
//函数inet_addr()和inet_network()把"255.255.255.255"当成了无效地址


IP地址
以“aaa.bbb.ccc.ddd”格式输入分配给打印机的IP地址。
“aaa”、“bbb”、“ccc”和“ddd”必须为0至255之间的数。但是，“aaa”不可为127或224至255之间的任何数。

子网掩码
以“aaa.bbb.ccc.ddd”格式输入子网掩码。
“aaa”、“bbb”、“ccc”和“ddd”必须为0至255之间的数。但是，255.255.255.255无效。

网关地址
以“aaa.bbb.ccc.ddd”格式输入网关地址。
“aaa”、“bbb”、“ccc”和“ddd”必须为0至255之间的数。但是，“aaa”不可为127或224至255之间的任何数。

*/
