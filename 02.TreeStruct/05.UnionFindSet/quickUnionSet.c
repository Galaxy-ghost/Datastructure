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

// 普通的查找算法，没有进行路径压缩，查找父节点的时候要挨个查找
static int findRootIndexNormal(QuickUnionSet *setQU, Element e) {
    // 找e的父亲，再找这个父亲的父亲，直到发现父亲的父亲是自己，那就是根了
    int curIndex = findIndex(setQU, e);		// 如果为-1 补
    // 向上遍历
    while (setQU->parent[curIndex] != curIndex) {
        curIndex = setQU->parent[curIndex];			// 将父节点ID作为下一个寻找的ID号
    }
    return curIndex;
}

// 入栈操作
static SetNode *push(SetNode *stack, int index) {
    SetNode *node = (SetNode *)malloc(sizeof (SetNode));
    if (node == NULL) {
        return NULL;
    }
    node->index = index;
    node->next = stack;
    return node;
}

// 出栈操作
static SetNode *pop(SetNode *stack, int *index) {
    SetNode *tmp = stack;
    *index = stack->index;
    stack = stack->next;
    free(tmp);
    return stack;
}

// 带路径压缩的查找算法，在查找祖先节点的路径上，将所有节点的父节点全部指向其祖先节点
// 这里使用的是非递归写法，即使用栈结构
static int findRootIndex(QuickUnionSet *setQU, Element e) {
    // 找e的父亲，再找这个父亲的父亲，直到发现父亲的父亲是自己，那就是根了
    int curIndex = findIndex(setQU, e);
    if (curIndex == -1) {
        return -1;
    }
    SetNode *path = NULL;
    while (setQU->parent[curIndex] != curIndex) {
        path = push(path, curIndex);
        curIndex = setQU->parent[curIndex];			// 将父节点ID作为下一个寻找的ID号
    }

    while (path) {
        int pos;
        path = pop(path, &pos);
        setQU->parent[pos] = curIndex;
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
