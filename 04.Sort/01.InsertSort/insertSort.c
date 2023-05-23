//
// Created by Galaxy. on 2023/5/21.
//

#include "insertSort.h"

//  NOTE :
//  默认第一个元素处于有序区域
//  待插入的元素i在有序区域从后往前比对
//      如果待插入的元素 < 有序区域的值，有序区域向后移动一位
//      插入查找位置为[0,i - 1]
void insertSort(SortTable *table) {
    for (int i = 1; i < table->length; i++) {
        if (table->data[i].key < table->data[i - 1].key) {
            Element temp = table->data[i];
            int j = i -1;
            while (j > -1 && table->data[j].key > temp.key) {
                table->data[j + 1] = table->data[j];
                j--;
            }
            table->data[j + 1] = temp;
        }
    }
}

void insertSortExchange(SortTable *table) {
    // 将无序区域的值与前面有序区域的值进行逐个比对
    for (int i = 1; i < table->length; i++) {
        Element temp = table->data[i];
        int j;
        for (j = i; j > 0 && table->data[j - 1].key > temp.key; --j) {
            swapElement(&table->data[j], &table->data[j - 1]);
        }
        table->data[j] = temp;
    }
}

void shellSort(SortTable *table) {
    // gap表示步长
    int gap;
    for (gap = table->length >> 1; gap > 0; gap >>= 1) {
        for (int i = gap; i < table->length; ++i) {
            Element temp = table->data[i];
            int j;
            for (j = i; j >= gap && table->data[j - gap].key > temp.key; j -= gap) {
                swapElement(&table->data[j], &table->data[j - gap]);
            }
//            table->data[j] = temp;
        }
    }
}

