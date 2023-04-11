//
// Created by Galaxy. on 2023/1/19.
//

#ifndef DATASTRUCTURE_BINARYTREE_H
#define DATASTRUCTURE_BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
typedef char Element;
// 树的节点结构
typedef struct treeNode {
    Element data;
    struct treeNode *left;          // 树的左孩子
    struct treeNode *right;        // 树的右孩子
}TreeNode;
typedef TreeNode* pTreeNode;

// 树的描述信息结构
typedef struct {
    struct treeNode *root;          // 根节点
    int count;                      // 树节点的数量
}BinaryTree;

BinaryTree *createBinaryTree(TreeNode *root);               // 初始化新的二叉树
void releaseBinaryTree(BinaryTree *tree);                                   // 释放二叉树
TreeNode *createTreeNode(Element e);                        // 创建树的节点
void insertBinaryTree(BinaryTree *tree, TreeNode *parent, TreeNode *left, TreeNode *right);      // 二叉树插入新的节点
void preOrderBTreeRecur(BinaryTree *tree);                  // 树的先序遍历，使用递归方法
void visitTreeNode(TreeNode *node);                         // 访问树的一个节点
void inOrderBTreeRecur(BinaryTree *tree);                   // 树的中序遍历，使用递归方法
void postOrderBTreeRecur(BinaryTree *tree);                 // 树的后序遍历，使用递归方法
void levelOrderBTree(BinaryTree *tree);                     // 二叉树的层序遍历

void preOrderBTreeNoRecur(BinaryTree *tree);                // 二叉树的先序遍历，不使用递归方法
void inOrderBTreeNoRecur(BinaryTree *tree);                 // 二叉树的中序遍历，不使用递归方法
void postOrderBTreeNoRecur(BinaryTree *tree);               // 二叉树的后序遍历，不使用递归方法


#endif //DATASTRUCTURE_BINARYTREE_H
