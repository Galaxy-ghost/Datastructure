//
// Created by Galaxy. on 2023/1/14.
//

#ifndef DATASTRUCTURE_ARRAYQUEUE_H
#define DATASTRUCTURE_ARRAYQUEUE_H

/* 顺序队列（循环队列）
 * rear指针数据是有效位数据
 */
#include "common.h"
#define MaxQueue 5
typedef struct {
    Element data[MaxQueue];
    int front;
    int rear;
}ArrayQueue;

ArrayQueue *createArrayQueue();                         // 初始化顺序队列
void releaseArrayQueue(ArrayQueue *queue);              // 释放队列
int enterArrayQueue(ArrayQueue *queue, Element e);      // 入队操作
int deleteArrayQueue(ArrayQueue *queue, Element *e);    // 出队操作

#endif //DATASTRUCTURE_ARRAYQUEUE_H
