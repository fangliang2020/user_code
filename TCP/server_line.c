#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

#define SERVER_PORT 8180
#define C_QUEUE     10 

/************************************************************
15*函数功能描述：从8180端口接收客户端数据
16*输入参数：无
17*输出参数：打印客户IP以及发来的信息
18*返回值：无
19*修改日期		版本号		修改人		修改内容
20*2020/05/13		v1.0.0		zonghzha	reat
21*************************************************************/

int main(int argc, char **argv)
{
    char buf[512];
    int len;
    int duty_socket;
    int customer_socket;
    struct sockaddr_in socket_server_addr;
    struct sockaddr_in socket_client_addr;
    int ret;
    int addr_len;

    signal(SIGCHLD, SIG_IGN);
	
	/* 服务器端开始建立socket描述符 */
    duty_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (duty_socket == -1)
    {
       printf("socket error");
        return -1;
    }
    
	/* 服务器端填充 sockaddr_in结构 */
    socket_server_addr.sin_family   = AF_INET;
	/*端口号转换为网络字节序*/
    socket_server_addr.sin_port     = htons(SERVER_PORT);
	/*接收本机所有网口的数据*/
    socket_server_addr.sin_addr.s_addr  = INADDR_ANY;
    memset(socket_server_addr.sin_zero, 0, 8);
    
	/* 捆绑sockfd描述符 */
    ret = bind(duty_socket, (const struct sockaddr *)&socket_server_addr, sizeof(struct sockaddr));
    if (ret == -1)
    {
        printf("bind error!\n");
       return -1;
    }
    ret = listen(duty_socket, C_QUEUE);
    if (ret == -1)
    {
        printf("listen error!\n");
        return -1;
    }
    
    while (1)
    {
       addr_len = sizeof(struct sockaddr);
		/* 服务器阻塞,直到客户程序建立连接 */
        customer_socket = accept(duty_socket, (struct sockaddr *)&socket_client_addr, &addr_len);
        if (customer_socket != -1)
        {
			/*inet_ntoa的作用是将一个32位Ipv4地址转换为相应的点分十进制数串*/
            printf("Get connect from %s\n", inet_ntoa(socket_client_addr.sin_addr));
        }
        if (!fork())
        {
            while (1)
            {
               memset(buf, 512, 0);
				/*接收数据*/
                len = recv(customer_socket, buf, sizeof(buf), 0);
                buf[len] = '\0';
                if (len <= 0)
               {
                    close(customer_socket);
                   return -1;
                }
                else
                {
                    printf("Get connect from %s, Msg is %s\n", inet_ntoa(socket_client_addr.sin_addr), buf);
                }
            }
        }
    }
    
    close(duty_socket);
    return 0;
    }
