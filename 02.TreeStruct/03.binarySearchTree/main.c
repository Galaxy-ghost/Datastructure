//
// Created by Galaxy. on 2023/4/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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


int main() {
    test01();
    return 0;
}
