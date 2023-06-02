//
// Created by Galaxy. on 2023/6/1.
//

#include "mergeSort.h"
#include <malloc/_malloc.h>
#include <stdio.h>

// 合并操作
// 1. 首先将两个子任务的元素排序记录
// 2. 将子任务的元素排序合并到原table中
static void merge(SortTable *table, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    // 分配空间
    Element *aux1 = (Element *) malloc(sizeof(Element) * n1);
    Element *aux2 = (Element *) malloc(sizeof(Element) * n2);
    if (aux1 == NULL || aux2 == NULL) {
        fprintf(stderr, "malloc error!\n");
        return;
    }
    for (int i = 0; i < n1; i++) {
        aux1[i] = table->data[left + i];
    }

    for (int i = 0; i < n2; i++) {
        aux2[i] = table->data[mid + 1 + i];
    }
    
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (aux1[i].key <= aux2[j].key) table->data[k++] = aux1[i++];
        else table->data[k++] = aux2[j++];
    }
    while (i < n1) table->data[k++] = aux1[i++];
    while (j < n2) table->data[k++] = aux2[j++];
    // 释放临时空间
    free(aux2);
    free(aux1);
}


static void mergeLoop (SortTable *table, int left, int right) {
    if (left >= right) return;
    // 完成子任务
    int mid = (right - left) / 2 + left;
    mergeLoop(table, left, mid);
    mergeLoop(table, mid + 1, right);
    // 进行合并
    merge(table, left, mid, right);
}

void mergeSort(SortTable *table) {
    mergeLoop(table, 0, table->length - 1);
}


