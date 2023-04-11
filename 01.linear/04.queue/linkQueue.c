//
// Created by Galaxy. on 2023/1/14.
//

#include "linkQueue.h"

LinkQueue *createLinkQueue() {
    LinkQueue *queue = (LinkQueue *)malloc(sizeof(LinkQueue));
    if (queue == NULL){
        printf("malloc error!\n");
        return NULL;
    }
    queue->front = queue->rear = NULL;
    queue->cnt = 0;
    return queue;
}

int enterLinkQueue(LinkQueue *queue, Element e) {
    QNode *node = (QNode *)malloc(sizeof(QNode));
    if (node == NULL){
        printf("malloc error!\n");
        return -1;
    }
    node->data = e;
    node->next = NULL;
    if (queue->rear){
        queue->rear->next = node;
        queue->rear = node;
    }else{
        queue->rear = queue->front = node;
    }
    queue->cnt++;
    return 0;
}

int deleteLinkQueue(LinkQueue *queue, Element *e) {
    // 首先判断队列是否为空
    if (queue->front == NULL){
        printf("queue empty!\n");
        return -1;
    }
    *e = queue->front->data;
    QNode *tmp = queue->front;
    queue->front = tmp->next;
    free(tmp);
    queue->cnt--;
    // 当队列为空的时候，rear指向的是一个已经被释放的指针，这时候需要将它指向空
    if(queue->front == NULL){
        queue->rear = NULL;
    }
    return 0;
}

void releaseLinkQueue(LinkQueue *queue) {
    if(queue){
        // 备份思想
        QNode *node;
        while(queue->front){
            node = queue->front;
            queue->front = node->next;
            free(node);
            queue->cnt--;
        }
        printf("queue have %d nodes!\n",queue->cnt);
        // 释放表头
        free(queue);
    }
}





