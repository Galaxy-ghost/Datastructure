//
// Created by Galaxy. on 2023/2/6.
//

#ifndef DATASTRUCTURE_THREADEDBTREE_H
#define DATASTRUCTURE_THREADEDBTREE_H

typedef char Element;
// 线索二叉树的节点结构
typedef struct treeNode {
    Element data;
    struct treeNode *left;
    struct treeNode *right;
    int ltag;                       // 0表示指向左孩子节点，1表示指向前驱节点
    int rtag;                        // 0表示指向右孩子节点，1表示指向后继节点
}TBTNode;
// 线索二叉树的描述信息结构
typedef struct {
    TBTNode *root;                   // 线索二叉树的根节点
    int count;                      // 记录线索二叉树的节点数量
}ThreadedBTree;

ThreadedBTree *createThreadedBTree(TBTNode *root);          // 初始化线索二叉树
void releaseThreadedBTree(ThreadedBTree *tree);             // 释放线索二叉树
TBTNode *createTBTNode(Element e);                          // 初始化二叉树节点
void insertThreadedBTree(ThreadedBTree *tree, TBTNode *parent, TBTNode *lchild, TBTNode *rchild);    // 二叉树插入节点
void visitTBTNode(TBTNode *node);                           // 访问二叉树节点

// 中序线索化树
void inOrderThreadedTree(ThreadedBTree *tree);
// 按照已经线索化后的树进行中序遍历
void inOrderTBTree(ThreadedBTree *tree);

#endif //DATASTRUCTURE_THREADEDBTREE_H
