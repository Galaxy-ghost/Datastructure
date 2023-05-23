//
// Created by Galaxy. on 2023/5/21.
//

#include "sortHelper.h"
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void swapElement(Element *e1, Element *e2) {
    Element tmp;
    memcpy(&tmp, e1, sizeof(Element));
    memcpy(e1, e2, sizeof(Element));
    memcpy(e2, &tmp, sizeof(Element));
}

void releaseSortTable(SortTable *table) {
    if (table) {
        if (table->data) {
            free(table->data);
        }
        free(table);
    }
}

SortTable *generateRandomArray(int n, int low, int high) {
    SortTable *table = (SortTable *)malloc(sizeof (SortTable));
    if (table == NULL) {
        fprintf(stderr, "malloc error!\n");
        return NULL;
    }
    table->length = n;
    table->data = (Element *)malloc(sizeof (Element) * n);
    if (table->data == NULL) {
        fprintf(stderr, "data malloc error!\n");
        free(table);
        return NULL;
    }
    srand(time(NULL) + 1);
    for (int i = 0; i < n; i++) {
        table->data[i].key = rand() % (high - low + 1) + low;    
        table->data[i].data = NULL;
    }
    return table;
}

SortTable *generateLinerArray(int n, int swapTimes) {
    SortTable *table = (SortTable *) malloc(sizeof (Element) * n);
    if (table == NULL) {
        fprintf(stderr, "malloc error!\n");
        return NULL;
    }
    table->length = n;
    table->data = (Element *)malloc(sizeof (Element) * n);
    if (table->data == NULL) {
        fprintf(stderr, "data malloc error!\n");
        free(table);
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        table->data[i].key = i;
        table->data[i].data = NULL;
    }
    srand(time(NULL) + 2);
    // 根据swaptimes进行数据交换
    for (int i = 1; i <= swapTimes; i++) {
        int pos1 = rand() % n;
        int pos2 = rand() % n;
        swapElement(&table->data[pos1], &table->data[pos2]);
    }
    
    return table;
}

// 拷贝一个同样的排序表以便进行测试
SortTable *copySortTable(SortTable *Old) {
    SortTable *table = (SortTable *)malloc(sizeof (SortTable));
    if (table == NULL) {
        fprintf(stderr, "malloc error!\n");
        return NULL;
    }
    table->length = Old->length;
    table->data = (Element *)malloc(sizeof (Element) * Old->length);
    if (table->data == NULL) {
        fprintf(stderr, "data malloc error!\n");
        free(table);
        return NULL;
    }
    
    for (int i = 0; i < Old->length; i++) {
        table->data[i].key = Old->data[i].key;
        table->data[i].data = Old->data[i].data;
    }

    return table;
}

static enum sortStatus checkData(SortTable *table) {
    for (int i = 0; i < table->length - 1; ++i) {
        if (table->data[i].key > table->data[i + 1].key) {
            printf("Check Sort Data Failed: %d : %d\n", table->data[i].key, table->data[i + 1].key);
            return failed;
        }
    }
    return success;
}


void testSort(const char *sortName, sortHandler sort, SortTable *table) {
    clock_t start = clock();
    sort(table);
    clock_t end = clock();
    if (checkData(table) == failed) {
        printf("%s failed!\n", sortName);
        return;
    }
    printf("%s cost time: %fs.\n", sortName, (double) (end - start) / CLOCKS_PER_SEC);
}

