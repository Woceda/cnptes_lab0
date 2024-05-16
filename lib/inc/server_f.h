#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <pthread.h>
#include <mqueue.h>
#include <unistd.h>
#include <errno.h>


/**
 * @brief 初始化函数,用于与net虚拟链路连接，仅能够在使用init（）后使用send_f与recive_f
*/
int init();

/**
 * @brief 数据帧发送函数，用于发送数据帧
 * 会将传入的data发送至server，并不会释放data，请手动释放
 * @param data 需要发送的数据帧
 * @param data_len 数据长度，请不要超过256
 * @return 0 ：成功 -1： 失败
*/
int send_f(uint8_t *data, uint32_t data_len);

/**
 * @brief 数据帧接收函数，用于接收数据帧
 * 将会检查是否有数据帧到达，如果有，将返回数据帧长度，并将数据帧内容写入data中
 * @param data 用于存放接收到的数据帧的缓冲区
 * @param data_len 接收到的数据帧的长度
 * @return 0: 未接收到数据帧 其他：接收到的数据帧长度
*/
int recive_f(uint8_t *data, uint32_t data_len);