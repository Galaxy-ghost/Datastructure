//
// Created by Galaxy. on 2023/2/6.
//

#include "threadedBTree.h"
#include <stdio.h>
#include <stdlib.h>

ThreadedBTree *createThreadedBTree(TBTNode *root) {
    ThreadedBTree *tree = (ThreadedBTree *)malloc(sizeof(ThreadedBTree));
    if (tree == NULL) {
        fprintf(stderr, "tree malloc error!\n");
        return NULL;
    }
    if (root) {
        tree->root = root;
        tree->count = 1;
    } else {
        tree->root = NULL;
        tree->count = 0;
    }
    return tree;
}

/*
 * 后序遍历释放节点，但是找后序节点的时候需要找非线索化的节点
 */
static void releaseTBTNode(ThreadedBTree *tree, TBTNode *node) {
    if (node) {
        if (node->ltag == 0) {
            releaseTBTNode(tree, node->left);
        }
        if (node->rtag == 0) {
            releaseTBTNode(tree, node->right);
        }
        free(node);
        tree->count--;
    }
}

/*
 * 释放线索树
 */
void releaseThreadedBTree(ThreadedBTree *tree) {
    if (tree) {
        releaseTBTNode(tree, tree->root);
        printf("tree has %d node!\n", tree->count);
        free(tree);
    }
}

TBTNode *createTBTNode(Element e) {
    TBTNode *node = (TBTNode *)malloc(sizeof(TBTNode));
    if (node == NULL) {
        fprintf(stderr, "malloc error!\n");
        return NULL;
    }
    node->left = NULL;
    node->right = NULL;
    node->data = e;
    node->ltag = node->rtag = 0;
    return node;
}

void insertThreadedBTree(ThreadedBTree *tree, TBTNode *parent, TBTNode *lchild, TBTNode *rchild) {
    if (tree && parent) {
        parent->left = lchild;
        parent->right = rchild;
        if (lchild) {
            tree->count++;
        }
        if (rchild) {
            tree->count++;
        }
    }
}

/*
 * 树节点的访问
 */
void visitTBTNode(TBTNode *node) {
    if (node) {
        printf("\t%c",node->data);
    }
}

static TBTNode *pre = NULL;
static void inOrderThreading(TBTNode *node) {
    if (node) {
        inOrderThreading(node->left);
        if (node->left == NULL) {		// 更新当前节点的前驱
            node->ltag = 1;
            node->left = pre;
        }
        // 当前节点会不会是前面那个节点后继节点
        if (pre && pre->right == NULL) {
            pre->rtag = 1;
            pre->right = node;
        }
        pre = node;
        inOrderThreading(node->right);
    }
}

void inOrderThreadedTree(ThreadedBTree *tree) {
    if (tree) {
        inOrderThreading(tree->root);
    }
}

void inOrderTBTree(ThreadedBTree *tree) {
    TBTNode *node = tree->root;
    while (node) {
        while (node->ltag == 0) {
            node = node->left;
        }
        visitTBTNode(node);
        // 一直向右开始遍历，只要右边是后继标记，就查看
        while (node->rtag && node->right) {
            node = node->right;
            visitTBTNode(node);
        }
        node = node->right;
    }
}
