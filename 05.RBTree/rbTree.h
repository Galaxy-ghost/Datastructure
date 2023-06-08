//
// Created by Galaxy. on 2023/6/5.
//

#ifndef DATASTRUCTURE_RBTREE_H
#define DATASTRUCTURE_RBTREE_H

enum RBColor {
    RED,
    BLACK
};

typedef int KeyType;

// 红黑树的节点结构
typedef struct RBNode
{
    char color; // 节点的颜色
    KeyType key;
    struct RBNode* parent;
    struct RBNode* left;
    struct RBNode* right;
} RBNode;

// 红黑树的结构
typedef struct
{
    RBNode* root; // 根节点
    int num;
} RBTree;

RBTree* createRBTree();
void insertRBTree(RBTree* tree, int key);
void deleteRBTree(RBTree* tree, KeyType key);
void printRBTree(RBNode* node, int key, int dir);
void releaseRBTree(RBTree* tree);
// 查找红黑树的节点
RBNode *searchRBNode(RBTree *tree, KeyType key);

#endif // DATASTRUCTURE_RBTREE_H
