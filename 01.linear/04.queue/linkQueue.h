//
// Created by Galaxy. on 2023/1/14.
//

#ifndef DATASTRUCTURE_LINKQUEUE_H
#define DATASTRUCTURE_LINKQUEUE_H

#include "common.h"
// 链式节点类型
typedef struct qNode {
    Element data;
    struct qNode *next;
}QNode;
// 链式表头类型
typedef struct {
    QNode *front;   // 队头指针
    QNode *rear;    // 队尾指针
    int cnt;        // 用来记录队列中元素的数量
}LinkQueue;

LinkQueue *createLinkQueue();                       // 初始化新的队列
void releaseLinkQueue(LinkQueue *queue);            // 释放队列
int enterLinkQueue(LinkQueue *queue, Element e);    // 入队
int deleteLinkQueue(LinkQueue *queue, Element *e);              // 出队

#endif //DATASTRUCTURE_LINKQUEUE_H
