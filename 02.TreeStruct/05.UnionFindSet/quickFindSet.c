//
// Created by Galaxy. on 2023/4/19.
//

#include "quickFindSet.h"
#include <stdio.h>
#include <stdlib.h>

QuickFindSet *createQuickFindSet(int n) {
    QuickFindSet *setQF = (QuickFindSet *) malloc (sizeof (QuickFindSet));
    setQF->n = n;
    setQF->data = (Element *) malloc (sizeof(Element) * n);
    setQF->groupID = (int *) malloc (sizeof(int) * n);
    return setQF;
}

void releaseQuickFindSet(QuickFindSet *setQF) {
    if (setQF) {
        if (setQF->data) {
            free(setQF->data);
        }
        if (setQF->groupID) {
            free(setQF->groupID);
        }
        free(setQF);
    }
}

void initQuickFindSet(QuickFindSet *setQF, const Element *data, int n) {
    for (int i = 0; i < n; i++) {
        setQF->data[i] = data[i];
        setQF->groupID[i] = i;
    }
}

// 找到对应元素在并查集下的索引
static int findIndex(QuickFindSet *setQF, Element x) {
    for (int i = 0; i < setQF->n; i++) {
        if (setQF->data[i] == x) {
            return i;
        }
    }
    return -1;
}

int isSameQF(QuickFindSet *setQF, Element a, Element b) {
    // 首先找到两个元素对应在并查集下的索引
    int aIndex = findIndex(setQF, a);
    int bIndex = findIndex(setQF, b);

    // 判断索引是否合法
    if (aIndex == -1 || bIndex == -1) {
        return 0;
    }

    return setQF->groupID[aIndex] == setQF->groupID[bIndex];
}

// 将元素a和元素b合并，将集团编号与b相同的所有元素的编号全部改成a的编号
void unionQF(QuickFindSet *setQF, Element a, Element b) {
    int aIndex = findIndex(setQF, a);
    int bIndex = findIndex(setQF, b);
    int bGroupID = setQF->groupID[bIndex];

    for (int i = 0; i < setQF->n; i++) {
        if (setQF->groupID[i] == bGroupID) {
            setQF->groupID[i] = setQF->groupID[aIndex];
        }
    }
}

