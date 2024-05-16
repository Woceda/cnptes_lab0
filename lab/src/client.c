#include "client.h"

/**
 * 连接建立发起函数
 */
int start_connect(uint16_t port)
{
    return 0;
}

int close_connect()
{
    return 0;
}

/**
 * 请完成相关内容，需要完成可靠传输与流式传输
 */
int send(uint8_t *data, uint32_t data_len)
{
    send_f(data,data_len);
    return 0;
}

/**
 * @brief 客户端函数
 * 需要先进行三次握手连接，之后进行数据的收发，最后完成连接释放
 * @param argc 参数数量
 * @param argv 参数
 */
int main(int argc, char *argv[])
{
    /** 初始化开始，请勿修改 */
    init();
    /** 初始化结束, 请在下方编写你的代码 */

    /** 设置端口号，请自行设计如何传入端口号 */
    int port;
    
    /** 设置端口号结束 */

    /** 开始握手 */
    start_connect(port);

    /** 握手结束 */

    char send_data[8196];

    char input[8196];
    while (1)
    {

        printf("Please input a message: ");
        scanf("%s", input);
        /** 设置断开连接的接口 */
        if (input[0] == '.' && input[1] == 'q')
        {
            close_connect();
            return 0;
        }
        uint8_t *send_data = malloc(strlen(input));
        memcpy(send_data, input, strlen(input));
        if (send(send_data, strlen(input)) == -1)
        {
            perror("mq_send");
        }
        memset(input, '\0', 8196);
    }
    return 0;
}