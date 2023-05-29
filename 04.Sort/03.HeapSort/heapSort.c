//
// Created by Galaxy. on 2023/5/29.
//

#include "heapSort.h"

void miniHeapSort(SortTable *table) {
    MiniHeap *miniHeap = createMiniHeap(table->length);
	for (int i = 0; i < table->length; ++i) {
		insertMiniHeap(miniHeap, table->data[i].key);
	}
	for (int i = 0; i < table->length; ++i) {
		table->data[i].key = extractTopMiniHeap(miniHeap);
	}
	releaseMiniHeap(miniHeap);
}

