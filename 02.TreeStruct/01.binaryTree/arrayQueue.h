//
// Created by Galaxy. on 2023/1/14.
//

#ifndef DATASTRUCTURE_ARRAYQUEUE_H
#define DATASTRUCTURE_ARRAYQUEUE_H

/* 顺序队列（循环队列）
 * rear指针数据是有效位数据
 */
#include "binaryTree.h"
#define MaxQueue 20
typedef struct {
    pTreeNode data[MaxQueue];
    int front;
    int rear;
}ArrayQueue;

ArrayQueue *createArrayQueue();                         // 初始化顺序队列
void releaseArrayQueue(ArrayQueue *queue);              // 释放队列
int enterArrayQueue(ArrayQueue *queue, pTreeNode e);      // 入队操作
int deleteArrayQueue(ArrayQueue *queue, pTreeNode *e);    // 出队操作

#endif //DATASTRUCTURE_ARRAYQUEUE_H
