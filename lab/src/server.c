#include "server.h"


/**
 * @brief 主程序,需要传入端口号,默认8080端口
 * @param argc 参数数量
 * @param argv 参数
 */
int main(int argc, char *argv[])
{

    /** 初始化开始，请勿修改 */
    init();
    /** 初始化结束, 请在下方编写你的代码 */

    printf("start recive\n");

    // 一下为示例代码，验证是否能够正常接收数据
    while (1)
    {
        uint8_t buffer[1024];
        int ret = recive_f(buffer, 1024);
        if (ret != 0)
        {
            printf("recive data: %s\n", buffer);
        }
    }

    return 0;
}