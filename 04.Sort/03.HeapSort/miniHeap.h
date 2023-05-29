//
// Created by Galaxy. on 2023/5/29.
//

#ifndef DATASTRUCTURE_MINIHEAP_H
#define DATASTRUCTURE_MINIHEAP_H
// 这里编写的是小根堆结构
#include "../sortHelper.h"

// 采用的是线性结构
typedef struct {
    keyType *data;
    int length; // 当前堆的元素个数
    int capacity; // 堆的最大容量
}MiniHeap;

// 创建一个最大容量为n的堆
MiniHeap *createMiniHeap(int n);
// 释放堆
void releaseMiniHeap(MiniHeap *heap);
// 向堆中插入元素
void insertMiniHeap(MiniHeap *heap, keyType key);
// 提取堆中的top元素
keyType extractTopMiniHeap(MiniHeap *heap);

#endif //DATASTRUCTURE_MINIHEAP_H
