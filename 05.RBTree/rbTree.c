//
// Created by Galaxy. on 2023/6/5.
//

#include "rbTree.h"

#include <stdio.h>
#include <stdlib.h>

// 红黑树的左旋操作
/* 将x进行左旋，将左、右、父节点进行更新
 *      px                              px
 *     /                               /
 *    x                               y
 *   /  \      --(左旋)-->           / \
 *  lx   y                          x  ry
 *     /   \                       /  \
 *    ly   ry                     lx  ly
 */
static void leftRotate(RBTree* tree, RBNode* x)
{
    RBNode* y = x->right;
    x->right = y->left;
    if (y->left) {
        y->left->parent = x;
    }
    if (x->parent) {
        if (x->parent->left == x) {
            x->parent->left = y;
        }
        else {
            x->parent->right = y;
        }
    }
    else {
        tree->root = y;
    }
    y->left = x;
    x->parent = y;
}

/* 将y进行右旋，将左、右、父节点进行更新
 *           py                               py
 *           /                                /
 *          y                                x
 *         /  \      --(右旋)-->            /  \
 *        x   ry                           lx   y
 *       / \                                   / \
 *      lx  rx                                rx  ry
 * */
static void rightRotate(RBTree* tree, RBNode* y)
{
    RBNode* x = y->left;
    y->left = x->right;
    if (x->right) {
        x->right->parent = y;
    }
    if (y->parent) {
        if (y->parent->left == y) {
            y->parent->left = x;
        }
        else {
            y->parent->right = x;
        }
    }
    else {
        tree->root = x;
    }
    x->right = y;
    y->parent = x;
}

RBTree* createRBTree()
{
    RBTree* tree = (RBTree*) malloc(sizeof(RBTree));
    tree->root = NULL;
    tree->num = 0;
    return tree;
}

static RBNode* createRBNode(int key)
{
    RBNode* node = (RBNode*) malloc(sizeof(RBNode));
    node->color = RED;
    node->key = key;
    node->left = node->right = node->parent = NULL;
    return node;
}

static void freeNode(RBTree* tree, RBNode *node) {
    if (node) {
        freeNode(tree, node->left);
        freeNode(tree, node->right);
        free(node);
        tree->num--;
    }
}

void releaseRBTree(RBTree* tree) {
    if (tree) {
        if (tree->root) {
            freeNode(tree, tree->root);
        }
        free(tree);
    }
}


// 红黑树的修正操作
// 1. 插入节点，如果父亲节点是黑色，就不需要调整
// 2. 父亲节点是红色
// 2.1 叔叔节点是红色
//      把父亲节点变为黑色，父亲节点和叔叔节点变成黑色，祖父节点变成红色，把它当作节点再进行循环判断操作
// 2.2 叔叔节点是黑色
// 2.2.1 父亲节点位置是左边，插入节点位置是左边，以祖父节点为支点进行右旋
// 2.2.2
// 父亲节点位置是左边，插入节点位置是右边，先以父亲节点为支点进行左旋，再以祖父节点为支点进行右旋
// 2.2.3 父亲节点位置是右边，插入节点位置是右边，以祖父节点为支点进行左旋
// 2.2.4
// 父亲节点位置是右边，插入节点位置是左边，先以父亲节点作为支点进行右旋，再以祖父节点为支点进行左旋
// 将父亲节点设置为黑色，祖父节点设置为红色
static void insertFixup(RBTree* tree, RBNode* node)
{
    RBNode *parent, *grandparent, *uncle;
    RBNode* tmp;
    parent = node->parent;
    while (parent && parent->color == RED) {
        grandparent = parent->parent;
        if (grandparent->left == parent) {
            uncle = grandparent->right;
        }
        else {
            uncle = grandparent->left;
        }

        if (uncle && uncle->color == RED) {
            uncle->color = BLACK;
            parent->color = BLACK;
            grandparent->color = RED;
            node = grandparent;
            parent = node->parent;
            continue;
        }
        else {
            if (grandparent->left == parent) { // L
                // R
                if (parent->right == node) {
                    leftRotate(tree, parent);
                    tmp = parent;
                    parent = node;
                    node = tmp;
                }
                // LL
                rightRotate(tree, grandparent);
                parent->color = BLACK;
                grandparent->color = RED;
            }
            else { // R
                // L
                if (parent->left == node) {
                    rightRotate(tree, parent);
                    tmp = parent;
                    parent = node;
                    node = tmp;
                }
                // RR
                leftRotate(tree, grandparent);
                parent->color = BLACK;
                grandparent->color = RED;
            }
        }
    }
    tree->root->color = BLACK;
}

// 红黑树的插入操作
void insertRBTree(RBTree* tree, int key)
{
    // 1. 初始化红黑树节点
    RBNode* node = createRBNode(key);
    // 2. 找到待插入的节点
    RBNode* cur = tree->root;
    RBNode* pre = NULL;
    while (cur) {
        pre = cur;
        if (node->key > cur->key) {
            cur = cur->right;
        }
        else if (node->key < cur->key) {
            cur = cur->left;
        }
        else {
            printf("Key: %d has already exists\n", key);
            return;
        }
    }
    // 3. 更新红黑树
    node->parent = pre;
    if (pre) {
        if (pre->key < key) {
            pre->right = node;
        }
        else {
            pre->left = node;
        }
    }
    else {
        tree->root = node;
        tree->root->color = BLACK;
        tree->num++;
        return;
    }
    // 4. 进行修正（修复红红节点）
    insertFixup(tree, node);
    tree->num++;
}

void printRBTree(RBNode* node, int key, int dir)
{
    if (node) {
        if (dir == 0) {
            printf("%d[%c] is root\n", node->key, (node->color == RED) ? 'R' : 'B');
        }
        else {
            printf(
                "%d[%c] is %d's %s\n",
                node->key,
                (node->color == RED) ? 'R' : 'B',
                key,
                (dir == 1) ? "right child" : "left child");
        }
        printRBTree(node->left, node->key, -1);
        printRBTree(node->right, node->key, 1);
    }
}

static void deleteFixup(RBTree* tree, RBNode* x, RBNode* parent)
{
    RBNode* w;
    while ((tree->root != x) && (x == NULL || x->color == BLACK)) {
        if (parent->left == x) { // x是父节点的左孩子
            w = parent->right;   // w为x的兄弟节点		R
            if (w->color == RED) {
                // case1 x的兄弟是红色
                w->color = BLACK;
                parent->color = RED;
                leftRotate(tree, parent); // 转化为兄弟节点是黑的情况
                w = parent->right;
            }
            // 兄弟节点都是黑色
            if ((!w->left || w->left->color == BLACK)
                && ((!w->right || w->right->color == BLACK))) {
                // case2 x的兄弟的两个孩子都是黑色
                w->color = RED;
                x = parent;
                parent = x->parent;
            }
            else {
                if (!w->right || w->right->color == BLACK) {
                    // case 3， x的兄弟节点左孩子是红色，右孩子是黑色的	 RL
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(tree, w);
                    w = parent->right;
                }
                // RR  case4
                w->color = parent->color;
                parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(tree, parent);
                break;
            }
        }
        else {
            w = parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                parent->color = RED;
                rightRotate(tree, parent);
                w = parent->left;
            }
            if ((!w->left || w->left->color == BLACK) && (!w->right) || w->right->color == BLACK) {
                // case2
                w->color = RED;
                x = parent;
                parent = x->parent;
            }
            else {
                if ((!w->left || w->left->color == BLACK)) {
                    // case 3
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(tree, w);
                    w = parent->left;
                }
                // case 4
                w->color = parent->color;
                parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(tree, parent);
                break;
            }
        }
    }
    if (tree->root) {
        tree->root->color = BLACK;
    }
}

static void deleteRBNode(RBTree* tree, RBNode* node)
{
    RBNode* y; // 真正删除的节点地址
    RBNode* x; // 替换节点
    RBNode* parent;
    if (node->left == NULL || node->right == NULL) { // 有一个孩子或没有孩子
        y = node;
    }
    else { // 拥有左右子树的节点，需要寻找后继节点
        y = node->right;
        while (y->left) {
            y = y->left;
        }
    }
    // 真正删除的节点找到，开始寻找替换节点
    if (y->left) {
        x = y->left;
    }
    else {
        x = y->right;
    }
    parent = y->parent;
    if (x) {
        x->parent = parent;
    }
    if (y->parent == NULL) {
        tree->root = x;
    }
    else if (y->parent->left == y) {
        y->parent->left = x;
    }
    else {
        y->parent->right = x;
    }
    // 更新有左右孩子的根节点的值
    if (y != node) { // 说明度为2
        node->key = y->key;
    }
    // 如果删除的节点是黑色，那么需要调整
    if (y->color == BLACK) {
        deleteFixup(tree, x, parent);
    }
    // 调整完或者删除节点是红色，直接释放
    tree->num--;
    free(y);
}

void deleteRBTree(RBTree* tree, KeyType key)
{
    RBNode* node = searchRBNode(tree, key);
    if (node) {
        deleteRBNode(tree, node);
    }
}

RBNode* searchRBNode(RBTree* tree, KeyType key)
{
    RBNode* node = tree->root;
    while (node) {
        if (key < node->key) {
            node = node->left;
        }
        else if (key > node->key) {
            node = node->right;
        }
        else {
            return node;
        }
    }
    return NULL;
}
