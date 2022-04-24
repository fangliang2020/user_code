#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8180
/************************************************************
12*函数功能描述：向指定IP的8180端口发送数据
13*输入参数：点分十进制服务器IP
14*输出参数：无
15*返回值：无
16*修改日期		版本号		修改人		修改内容
17*2020/05/13		v1.0.0		zonghzha	creat
18*************************************************************/

int main(int argc, char **argv)
{
   unsigned char buf[512];
   int len;
    struct sockaddr_in socket_server_addr;
    int ret;
    int addr_len;
    int client_socket;

   
    if (argc != 2)
    {
        printf("Usage:\n");
        printf("%s <server_ip>\n", argv[0]);
        return -1;
    }
    
    /* 客户程序开始建立 sockfd描述符 */
   client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1)
    {
        printf("socket error");
        return -1;
    }
   
	/* 客户程序填充服务端的资料 */
    socket_server_addr.sin_family   = AF_INET;
	/*主机字节序转换为网络字节序*/
    socket_server_addr.sin_port     = htons(SERVER_PORT);
    if (inet_aton(argv[1], &socket_server_addr.sin_addr) == 0)
    {
        printf("invalid server ip\n");
        return -1;
    }
    memset(socket_server_addr.sin_zero, 0, 8);
    /* 客户程序发起连接请求 */
    ret = connect(client_socket, (const struct sockaddr *)&socket_server_addr, sizeof(struct sockaddr));
    if (ret == -1)
    {
        printf("connect error!\n");
        return -1;
    }

    
    while (1)
    {
        if (fgets(buf, sizeof(buf), stdin))
        {
            len = send(client_socket, buf, strlen(buf), 0);
            if (len <= 0)
            {
                close(client_socket);
                return -1;
            }
        }
    }
    
    close(client_socket);
    return 0;
}
