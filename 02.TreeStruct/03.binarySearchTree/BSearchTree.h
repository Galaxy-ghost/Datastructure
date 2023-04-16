//
// Created by Galaxy. on 2023/4/12.
//

#ifndef DATASTRUCTURE_BSEARCHTREE_H
#define DATASTRUCTURE_BSEARCHTREE_H

typedef int Element;
// 定义节点结构
typedef struct bSNode {
    Element data;
    struct bSNode *left;
    struct bSNode *right;
}BSNode;
// 二叉搜索树结构
typedef struct {
    // 根节点
    BSNode *root;
    // 用来记录当前树中节点的个树
    int count;
}BSTree;

BSTree *createBSTree(); // 初始化二叉搜索树结构
void releaseBSTree(BSTree *tree); // 释放二叉搜索树
void inOrderBSTree(BSTree *tree); // 中序遍历二叉搜索树
void deleteBSTreeNoRecur(BSTree *tree, Element e); // 删除树中值为e的节点（非递归方式）
void deleteBSTreeRecur(BSTree *tree, Element e); // 删除树中值为e的节点（递归方式）
void insertBSTreeNoRecur(BSTree *tree, Element e); // 向二叉搜索树中插入一个元素（非递归方式）
void insertBSTreeRecur(BSTree *tree, Element e); // 用递归的方式向二叉搜索树中插入一个元素（递归方式）
int getBSNodeDepth(BSNode *node); // 计算二叉搜索树的高度
BSNode *searchBSTNode(BSTree *tree, Element e); // 在二叉搜索树中查找值为e的节点


#endif //DATASTRUCTURE_BSEARCHTREE_H
