//
// Created by Galaxy. on 2023/4/16.
//

#ifndef DATASTRUCTURE_AVLTREE_H
#define DATASTRUCTURE_AVLTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int Element;
// 定义AVL的节点结构
typedef struct AVLNode {
    Element data;
    struct AVLNode *left;
    struct AVLNode *right;
    int height; // 增加一个数据记录节点的高度
}AVLNode;
// 定义AVL结构
typedef struct {
    AVLNode *root;
    int count; // 记录节点个数
}AVLTree;

AVLTree *createAVLTree(); // 建立一棵新的平衡二叉树
void releaseAVLTree(AVLTree *tree); // 释放平衡二叉树
void visitAVLNode(AVLNode *node); // 访问平衡二叉树的节点
void inOrderAVLTree(AVLTree *tree); // 中序遍历平衡二叉树

// 插入元素到AVLTree
void insertAVLTree(AVLTree *tree, Element e);

#endif //DATASTRUCTURE_AVLTREE_H
