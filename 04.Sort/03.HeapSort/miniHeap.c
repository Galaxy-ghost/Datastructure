//
// Created by Galaxy. on 2023/5/29.
//

#include "miniHeap.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

MiniHeap* createMiniHeap(int n)
{
    MiniHeap* heap = (MiniHeap*) malloc(sizeof(MiniHeap));
    if (heap == NULL) {
        return NULL;
    }
    heap->data = (keyType*) malloc(sizeof(keyType) * (n + 1));
    memset(heap->data, 0, sizeof (keyType) * (n + 1));
    heap->capacity = n;
    heap->length = 0;
    return heap;
}

void releaseMiniHeap(MiniHeap *heap) {
    if (heap) {
        if (heap->data) {
            free(heap->data);
        }
        free(heap);
    }
}

static void shiftUp(MiniHeap *heap, int n) {
    while (n > 1 && heap->data[n / 2] > heap->data[n]) {
        heap->data[n] ^= heap->data[n / 2];
        heap->data[n / 2] ^= heap->data[n];
        heap->data[n] ^= heap->data[n / 2];
        n /= 2;
    }
}

void insertMiniHeap(MiniHeap *heap, keyType key) {
    if (heap->length + 1 > heap->capacity) {
        printf("mini heap is full!\n");
        return;
    }
    heap->data[++heap->length] = key;
    shiftUp(heap, heap->length);
}

// 首先要判断是否有孩子
// 然后将该元素与左右孩子的最小元素进行交换
// 如果发现本身元素比孩子元素要小，则结束循环
// 如果发现要大，就交换元素，并继续循环
static void shiftDown(MiniHeap *heap, int n) {
    while (n * 2 <= heap->length) {
        int index = n * 2;
        if (index + 1 <= heap->length && heap->data[index + 1] < heap->data[index]) {
            index++;
        }
        if (heap->data[n] <= heap->data[index]) {
            break;
        }
        heap->data[n] ^= heap->data[index];
        heap->data[index] ^= heap->data[n];
        heap->data[n] ^= heap->data[index];
        n = index;
    }
}

// 提取堆顶元素堆操作
// 将堆顶元素的值存入一个备份元素中
// 然后将最后一个元素插入到堆顶，进行下移操作
keyType extractTopMiniHeap(MiniHeap *heap)  {
    if (heap->length <= 0) {
        printf("NO ELEMENT!\n");
    }
    keyType tmp = heap->data[1];
    heap->data[1] = heap->data[heap->length];
    heap->length--;
    shiftDown(heap, 1);
    return tmp;
}














