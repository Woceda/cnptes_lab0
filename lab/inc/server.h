#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <pthread.h>
#include <mqueue.h>
#include <unistd.h>
#include <errno.h>

#include "server_f.h"

#define CHANNEL_MAX_MSG_SIZE 1020
#define CHANNEL_MAX_MSG_NUM 10
#define PORT 8080



typedef struct message{
    uint16_t src_port;
    uint16_t dist_port;
    uint32_t seq;
    uint32_t ack;
    uint8_t flag_ack;
    uint8_t flag_syn;
    uint8_t flag_fin;
    uint16_t win_size;
    uint16_t check_sum;
    uint32_t len;
    uint8_t *data;
}message;

typedef struct tcp_connect{
    uint16_t tar_port; //目的端口
    uint32_t seq_num;   //序列号
    uint32_t ack_num;   //确认号
    uint16_t window_size;   //窗口大小
    uint16_t state;    //状态
    uint16_t recv_window_size;   //接收窗口大小
    // mqd_t rec_t;
}tcp_connect;

typedef struct tcp_arry{
    tcp_connect *connects;
    int len;
}tcp_arry;