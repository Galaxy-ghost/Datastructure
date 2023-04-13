//
// Created by Galaxy. on 2023/4/12.
//

#include "BSearchTree.h"
#include <stdio.h>
#include <stdlib.h>

BSTree *createBSTree (){
    BSTree *tree = (BSTree *) malloc(sizeof(BSTree));
    if (tree == NULL) {
        printf("malloc error!\n");
        return NULL;
    }

    tree->root = NULL; // 初始时将root节点初始节点置于空
    tree->count = 0;
    return tree;
}

// 通过后序遍历的方式来释放搜索树的节点
static void freeNode (BSTree *tree, BSNode *node) {
    if (node) {
        freeNode(tree, node->left);
        freeNode(tree, node->right);
        free(node);
        tree->count--;
    }
}

// 释放树的节点
void releaseBSTree (BSTree *tree) {
    if (tree) {
        // 首先先释放树中所有节点
        freeNode(tree, tree->root);
        // 释放树
        free(tree);
    }
}

static BSNode *createBNode (Element e) {
    BSNode *node = (BSNode *) malloc (sizeof (BSNode));
    if (node == NULL) {
        return NULL;
    }
    node->right = NULL;
    node->left = NULL;
    node->data = e;
    return node;
}

// 非递归的方式来向树中插入节点
void insertBSTreeNoRecur(BSTree *tree, Element e) {
    // 找到插入的那个节点
    BSNode *pre = NULL;
    BSNode *cur = tree->root;
    while (cur) {
        pre = cur;
        if (e < cur->data) {
            cur = cur->left;
        } else if (e > cur->data) {
            cur = cur->right;
        } else { // 如果该树中已经存在该值，就直接返回
            return;
        }
    }
    // 经过上述操作，cur一定已经指向了空
    // 分配一个节点内存
    BSNode *node = createBNode(e);
    // 判断该节点应该插入的位置并进行插入操作
    // 当前的cur指向空有两种情况，首先是根节点为空，那么此时pre指针也指向空，然后是cur为空，这时候pre指针指向的就是插入的节点
    if (pre) {
        if (e < pre->data) {
            pre->left = node;
        } else {
            pre->right = node;
        }
    } else {						// 树中还没有根
        tree->root = node;
    }
    tree->count++;
}

// 在二叉搜索树中搜索值为e的节点，将节点返回
BSNode *searchBSTNode(BSTree *tree, Element e) {
    // 定义一个辅助指针来查找值
    BSNode *node = tree->root;

    while (node) {
        // 二叉搜索树中左子树的值都小于根的值
        if (e < node->data) {
            node = node->left;
        } else if (e > node->data) {
            node = node->right;
        } else {
            return node;
        }
    }

    return NULL;
}

void visitNode(BSNode *node) {
    if (node) {
        printf("\t%d", node->data);
    }
}

static void inOrder(BSNode *node) {
    if (node) {
        inOrder(node->left);
        visitNode(node);
        inOrder(node->right);
    }
}


void inOrderBSTree(BSTree *tree){ 
   if (tree) {
    inOrder(tree->root);
    } 
}
