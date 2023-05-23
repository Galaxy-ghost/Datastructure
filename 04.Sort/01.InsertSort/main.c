//
// Created by Galaxy. on 2023/5/21.
//
#include "insertSort.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 10000;	// 增大数字
	SortTable *table1 = generateRandomArray(n, 0, n);
	SortTable *table2 = copySortTable(table1);
	SortTable *table3 = copySortTable(table1);
	SortTable *table4 = generateLinerArray(n, 10);

	testSort("random insertSort: ", insertSortExchange, table1);
	testSort("random insertSort: ", insertSort, table2);
    testSort("shell  insertSort: ", shellSort, table3);
	testSort("linear insertSort: ", insertSort, table4);

	releaseSortTable(table1);
	releaseSortTable(table2);
	releaseSortTable(table3);
	releaseSortTable(table4);
    return 0;
}
