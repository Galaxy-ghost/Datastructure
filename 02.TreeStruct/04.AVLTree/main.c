//
// Created by Galaxy. on 2023/4/16.
//

#include "avlTree.h"
#include <stdio.h>

void test01(){
    Element data[] = {40, 66, 67, 90, 34, 50, 20, 13};
    AVLTree *tree = createAVLTree();
    if (tree == NULL) {
        printf("malloc error\n");
        return ;
    }

    for (int i = 0; i < sizeof (data)/ sizeof (data[0]); i++) {
        insertAVLTree(tree, data[i]);
    }

    printf("树的中序遍历为：");
    inOrderAVLTree(tree);
    printf("\n平衡二叉树的高度为:%d\n", tree->root->height);

    releaseAVLTree(tree);
    return ;
}

int main(){
    test01();
    return 0;
}
