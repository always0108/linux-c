/*************************************************************************
	> File Name: show_files.c
	> Author: limeng
	> Mail: ldx19980108@gmail.com
	> Created Time: 2017年07月19日 星期三 15时35分34秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>

int my_readir(const char *path)
{
    DIR *dir;
    struct dirent *ptr;
    
    if((dir=opendir(path))==NULL){
        perror("opendir");
        return -1;
    }
    while((ptr = readdir(dir))!=NULL){
        printf("file name: %s\n",ptr->d_name);
    }
    closedir(dir);

    return 0;
}

int main(int argc,char ** argv)
{
    if(argc<2){
        printf("listfile <target path>\n");
        exit(1);
    }

    if(my_readir(argv[1])<0){
        exit(1);
    }

    return 0;
}

