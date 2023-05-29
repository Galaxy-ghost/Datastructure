//
// Created by Galaxy. on 2023/5/29.
//

#include "miniHeap.h"
#include "heapSort.h"
#include <stdio.h>

void test01() {
	int data[] = {9, 3, 7, 6, 5, 1, 10, 2};
	int n = 20;
	MiniHeap *miniHeap = createMiniHeap(n);
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); ++i) {
		insertMiniHeap(miniHeap, data[i]);
	}
	printf("array: ");
	for (int i = 1; i <= miniHeap->length; ++i) {
		printf("\t%d", miniHeap->data[i]);
	}
	printf("\nextra: ");
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); ++i) {
		printf("\t%d", extractTopMiniHeap(miniHeap));
	}
	// keyType tmp = extractTopMiniHeap(miniHeap);
	// while (tmp) {
	// 	printf("\t%d", tmp);
	// 	tmp = extractTopMiniHeap(miniHeap);
	// }
	releaseMiniHeap(miniHeap);
}

void test02() {
    int n = 100000;
    SortTable *table = generateRandomArray(n, 0, n);
    testSort("HeapSort: ", miniHeapSort, table);
	releaseSortTable(table);
}

int main() {
    test02();
    return 0;
}
