//
// Created by Galaxy. on 2023/4/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "BSearchTree.h"

void test01() {
    BSTree * tree = createBSTree();
    Element data[] = {98, 43, 76, 144, 245, 8};

    if (tree == NULL) {
        return ;
    }

    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        insertBSTreeNoRecur(tree, data[i]);
    }

    printf("二分搜索树的中序遍历为：");
    inOrderBSTree(tree);

    releaseBSTree(tree);
}

// data是数据数组，n是数组中元素个树，cnt是查找测试次数，value是需要查找的值
void linearFindTest (Element *data, int n, int cnt, int value) {
    for (int i = 0;i < cnt; i++) {
        for (int j = 0; j < n; j++) {
            if (data[j] == value) {
                printf("!!!!! Value Find !!!!!\n");
                return ;
            }
        }
    }
}

// tree是二叉线索树，cnt是查找测试的次数，value是需要查找的值
void BSTreeFindTest (BSTree *tree, int cnt, int value) {
    for (int i = 0; i < cnt; i++) {
        BSNode *node = searchBSTNode(tree, value); 
        if (node) {
            printf("!!!!! Value Find !!!!!\n");
            return;
        }
    }
} 

void test02() {
    int n = 10000;
    Element m = n + 5000;
    clock_t start, end;
    // 创建n个元素，取值范围在1-m
    Element *data = (Element *)malloc (sizeof (Element) * n);
    // 随机数种子
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        data[i] = rand() % m + 1;
    }
    // 测试线性查找需要的时间
    start = clock();
    linearFindTest(data, n, 10000, m + 50);
    end = clock();
    printf("线性查找需要的时间为：%f.\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 测试二叉线索树查找的时间，将线性和二叉树寻找的时间进行对比
    BSTree *tree = createBSTree();
    // 将data中的数据按照二叉搜索树的插入方式全部插入到二叉树中 
    for (int i = 0; i < n; i++) {
        insertBSTreeNoRecur(tree, data[i]);
    }
    start = clock();
    BSTreeFindTest(tree, 10000, m + 50);
    end = clock();
    printf("二叉搜索查找需要的时间为：%f.\n", (double)(end - start) / CLOCKS_PER_SEC);
    releaseBSTree(tree);
    free(data);
}


int main() {
    test02();
    return 0;
}
