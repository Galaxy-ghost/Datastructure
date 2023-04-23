//
// Created by Galaxy. on 2023/4/22.
//

#include "huffmanTree.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static void selectNode (HuffmanTree tree, int n, int *s1, int *s2) {
    int min = 0;		// 假设最小值的索引号
    // 找到第一个最小值，假设空间中，第一个parent==0的元素，假设他就是最小值
    for (int i = 1; i <= n; ++i) {
        if (tree[i].parent == 0) {
            min = i;
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (tree[i].parent == 0) {
            if (tree[i].weight < tree[min].weight) {
                min = i;
            }
        }
    }
    *s1 =  min;
    // 开始找第二个
    for (int i = 1; i <= n; ++i) {
        if (tree[i].parent == 0 && i != *s1) {		// 排除第一个已经找到的最小值
            min = i;
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (tree[i].parent == 0 && i != *s1) {
            if (tree[i].weight < tree[min].weight) {
                min = i;
            }
        }
    }
    *s2 = min;
}

HuffmanTree createHuffmanTree(const int *w, int n) {
    HuffmanTree tree = NULL;
    // 最终节点数量为2 * n - 1
    int m = 2 * n - 1;
    // 申请内存，因为节点的数量是2 * n - 1，这里我们把0号位置作为标记位置不使用，所以最终申请2 * n个内存
    tree = (HuffmanTree) malloc(sizeof (HuffmanNode) * 2 * (m + 1));
    // 对[1....2 * n - 1]位置上的树进行初始化，使其父节点与孩子节点的信息都为0
    for (int i = 1; i <= m; i++) {
        tree[i].lChild = tree[i].rChild = 0;
        tree[i].parent = 0;
        tree[i].weight = 0;
    }
    // 将初始节点的信息更新
    for (int i = 1; i <= n; i++) {
        tree[i].weight = w[i - 1];
    }

    // ----------------  初始化结束，下面开始创建huffman树 ---------------
    int s1, s2;
    for (int i = n + 1; i <= m; i++) {
        // 从[1 ~ i - 1]的huffmanNode中找到权重最小的两个
        selectNode(tree, i - 1, &s1, &s2);
        tree[s1].parent = tree[s2].parent = i;
        tree[i].lChild = s1, tree[i].rChild = s2;
        tree[i].weight = tree[s1].weight + tree[s2].weight;
    }

    return tree;
}

void releaseHuffmanTree(HuffmanTree tree) {
    if (tree) {
        free (tree);
    }
}


HuffmanTree *createHuffmanCode(HuffmanTree tree, int n) {
    // 首先申请一个n个char内存，因为huffmancode的编码长度不可能超过n，保证这里不会越界
    char * temp = (char *)malloc (sizeof (char) * n);
    // 申请一个huffmancode空间
    HuffmanCode *codes = (HuffmanCode *)malloc(sizeof (HuffmanCode) * n);
    memset(codes, 0, sizeof (codes));
    // 通过使用临时变量来动态申请codes中的空间
    int start; // 在临时空间temp中指向huffman编码开始位置，这里是从后往前编码
    int pos; // 用来存储遍历过程的当前节点
    int p; // 用来存放当前父节点的索引
    // 对当前tree中节点进行遍历，只需要遍历前n个节点
    for (int i = 1; i <= n; i++) {
        start = n - 1;
        // 赋值/0使后续strcpy能顺利进行
        temp[start] = '\0';
        pos = i;
        p = tree[i].parent;
        while (p) {
            start--;
            temp[start] = tree[p].lChild == pos ? '0' : '1';
            pos = p;
            p = tree[p].parent;
        }
        codes[i - 1] = (HuffmanCode) malloc (sizeof (char) * (n - start));
        strcpy(codes[i - 1], &temp[start]);
    }
    free(temp);

    return codes;
}

void releaseHuffmanCode(HuffmanCode *codes, int n) {
    if (codes) {
        for (int i = 0; i < n; i++) {
            free(codes[i]);
        }
        free(codes);
    }
}
