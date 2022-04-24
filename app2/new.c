#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>



int main(int argc, char **argv)
{
    int fd_old,fd_new;
    char buf[1024];
    int len;

    //判断参数
    if(argc!=3)
    {
        printf("usage:%s <old-file> <new-file>\n",argv[0]);
        return -1;
    }
    //打开老文件 
    fd_old=open(argv[1],O_RDONLY);
    if(fd_old==-1)
    {
        printf("can not open file!\n");
        return -1;
    }
    //创建新文件
    fd_new=open(argv[2],O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP| S_IWGRP | S_IROTH | S_IWOTH);
   if (fd_new == -1)
    {
        printf("can not creat file %s\n", argv[2]);
        return -1;
    }
    //循环读写文件
    while((len=read(fd_old,buf,1024))>0)
    {
        if(write(fd_new,buf,len)!=len)
        {
            printf("can not write %s\n",argv[2]);
            return -1;
        }
    }
    close(fd_old);
    close(fd_new);
    return -1;
}