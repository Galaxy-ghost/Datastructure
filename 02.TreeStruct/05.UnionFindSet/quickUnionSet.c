//
// Created by Galaxy. on 2023/4/19.
//

#include "quickUnionSet.h"
#include <stdio.h>
#include <stdlib.h>

QuickUnionSet *createQuickUnionSet(int n) {
    QuickUnionSet *setQU = (QuickUnionSet *)malloc (sizeof (QuickUnionSet));
    setQU->n = n;
    setQU->data = (Element *)malloc(sizeof (Element) * n);
    setQU->parent = (int *) malloc (sizeof (Element) * n);
    setQU->size = (int *)malloc (sizeof (Element) *n);
    return setQU;
}

void releaseQuickUnionSet(QuickUnionSet *setQU) {
    if (setQU) {
        if (setQU->size) {
            free(setQU->size);
        }
        if (setQU->parent) {
            free(setQU->parent);
        }
        if (setQU->data) {
            free(setQU->data);
        }
        free(setQU);
    }
}

static int findIndex(QuickUnionSet *setQU, Element e) {
    for (int i = 0; i < setQU->n; i++) {
        if (e == setQU->data[i]) {
            return i;
        }
    }
    return 0;
}

void initQuickUnionSet(QuickUnionSet *setQU, const Element *data, int n) {
    for (int i = 0 ;i < n; i++) {
        setQU->data[i] = data[i];
        setQU->parent[i] = i;
        setQU->size[i] = 1;
    }
}

static int findQUIndex(QuickUnionSet *setQU, Element e) {
    for (int i = 0; i < setQU->n; i++) {
        if (e == setQU->data[i]) {
            return i;
        }
    }
    return -1;
}

static int findRootIndex(QuickUnionSet *setQU, Element e) {
    // 找e的父亲，再找这个父亲的父亲，直到发现父亲的父亲是自己，那就是根了
    int curIndex = findIndex(setQU, e);		// 如果为-1 补
    // 向上遍历
    while (setQU->parent[curIndex] != curIndex) {
        curIndex = setQU->parent[curIndex];			// 将父节点ID作为下一个寻找的ID号
    }
    return curIndex;
}

int isSameQU(QuickUnionSet *setQU, Element a, Element b) {
    int aRoot = findRootIndex(setQU, a);
    int bRoot = findRootIndex(setQU, b);

    if (aRoot == -1 || bRoot == -1) {
        return 0;
    }

    return aRoot == bRoot;
}


void unionQU(QuickUnionSet *setQU, Element a, Element b) {
    int aRoot = findRootIndex(setQU, a);
    int bRoot = findRootIndex(setQU, b);
    if (aRoot == -1 || bRoot == -1) {
        return ;
    }
    if (aRoot != bRoot) {			// a 和 b不在一个集合
        // 根据根节点元素个数来决定合并顺序
        int aSize = setQU->size[aRoot];
        int bSize = setQU->size[bRoot];
        if (aSize >= bSize) {		// 将b元素的根指向a元素的根
            setQU->parent[bRoot] = aRoot;
            setQU->size[aRoot] += bSize;	// a就是根，更新这个根中的元素个数
        } else {
            setQU->parent[aRoot] = bRoot;
            setQU->size[bRoot] += aSize;
        }
    }

}
