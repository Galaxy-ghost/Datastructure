//
// Created by Galaxy. on 2023/5/21.
//

#ifndef DATASTRUCTURE_INSERTSORT_H
#define DATASTRUCTURE_INSERTSORT_H
#include "../sortHelper.h"

// 直接插入排序
void insertSort(SortTable *table);
// 采用交换方式的插入排序（类比与扑克牌的交换）
void insertSortExchange(SortTable *table);
// 希尔排序
void shellSort(SortTable *table);
#endif //DATASTRUCTURE_INSERTSORT_H
