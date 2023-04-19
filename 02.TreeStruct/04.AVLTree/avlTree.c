//
// Created by Galaxy. on 2023/4/16.
//

#include "avlTree.h"

// 求出两数的最大值
static int maxNum(int a, int b) {
    return (a > b) ? a : b;
}

// 返回节点的高度
static int h(AVLNode *node) {
    if (node == NULL) {
        return 0;
    }else {
        return node->height;
    }
}

AVLTree *createAVLTree() {
    AVLTree *tree = (AVLTree *)malloc(sizeof (AVLTree));
    if (tree == NULL) {
        printf("malloc error!\n");
        return NULL;
    }

    tree->count = 0;
    tree->root = NULL;
    return tree;
}

// 用后序遍历的方式释放节点
static void freeNode(AVLTree *tree, AVLNode *node) {
    if (node) {
        freeNode(tree, node->left);
        freeNode(tree, node->right);
        free(node);
        tree->count--;
    }
}


void releaseAVLTree(AVLTree *tree) {
    if (tree) {
        freeNode(tree, tree->root);
        free(tree);
    }
}

void visitAVLNode(AVLNode *node) {
    if (node) {
        printf("\t<%d,%d>", node->data, node->height);
    }
}

static void inOrder(AVLNode *node) {
    if (node) {
        inOrder(node->left);
        visitAVLNode(node);
        inOrder(node->right);
    }
}

void inOrderAVLTree(AVLTree *tree) {
    if (tree) {
        inOrder(tree->root);
    }
}

/* 左旋操作
 *     px
 *     |
 *     x
 *   /  \
 * lx    y
 *      / \
 *     ly ry
 * */
static AVLNode *leftRotate(AVLNode *x) {
    AVLNode *y = x->right;
    x->right = y->left;
    y->left = x;
    // 经过上述步骤，节点已经部署完毕，但是x，y节点的高度产生变化，所以接下来要更新高度
    x->height = maxNum(h(x->left), h(x->right)) + 1;
    y->height = maxNum(h(y->left), h(y->right)) + 1;
    return y;
}


/* 右旋操作
 *       py
 *       |
 *       y
 *     /  \
 *    x   ry
 *   / \
 * lx  rx
 * */
static AVLNode *rightRotate(AVLNode *y) {
    AVLNode *x = y->left;
    y->left = x->right;
    x->right = y;
    // 更新x，y节点的高度
    y->height = maxNum(h(y->left), h(y->right)) + 1;
    x->height = maxNum(h(x->left), h(x->right)) + 1;
    return x;
}

static AVLNode * createAVLNode(Element e) {
    AVLNode *node = (AVLNode *)malloc(sizeof (AVLNode));
    node->height = 1;
    node->left = node->right = NULL;
    node->data = e;
    return node;
}

static int getBalance(AVLNode *node) {
    if (node == NULL) {
        return 0;
    }
    return h(node->left) - h(node->right);
}

static AVLNode *insertAVLNode(AVLTree *tree, AVLNode *node, Element e) {
    // 递归找到插入节点
    if (node == NULL) {
        tree->count++;
        return createAVLNode(e);
    }

    if (e < node->data) {
        node->left = insertAVLNode(tree, node->left, e);
    } else if (e > node->data) {
        node->right = insertAVLNode(tree, node->right, e);
    } else {
        return node;
    }
    // 归的过程中更新节点高度
    node->height = maxNum(h(node->left), h(node->right)) + 1;
    // 计算平衡因子
    int balance = getBalance(node);

    // 根据平衡因子进行操作
    // 如果balance > 1左边节点进行右旋操作
    if (balance > 1) {
        //  判断是否是LR形态，如果是LR形态还需要将左边节点进行一次左旋
        if (e > node->left->data) {
            node->left = leftRotate(node->left);
        }
        // 进行右旋操作
        return rightRotate(node);
    } else if (balance < -1) { // 小于-1的时候表示是R状态，最后要将当前节点进行左旋
        // 判断是否是RL形态，如果是RL形态还需要将右边节点进行一次右旋
        if (e < node->right->data) {
            node->right = rightRotate(node->right);
        }
        // 进行左旋操作
        return leftRotate(node);
    }

    // 如果没有进行旋转操作，则直接返回node
    return node;
}

void insertAVLTree(AVLTree *tree, Element e) {
   tree->root = insertAVLNode(tree, tree->root, e);
}

static AVLNode *deleteAVLNode(AVLTree *tree, AVLNode *node, Element e) {
    AVLNode *tmp;
    if (node == NULL) {
        return NULL;
    }
    // 首先找到要删除的节点
    if (e < node->data) {
        node->left = deleteAVLNode(tree, node->left, e);
    } else if (e > node->data) {
        node->right = deleteAVLNode(tree, node->right, e);
    } else { // 找到了该节点
        if (node->left == NULL || node->right == NULL) {
            tmp = node->left ? node->left : node->right;
            if (tmp == NULL){ // 度为0的情况，这时候就直接删除该节点
                free(node);
                tree->count--;
                return NULL;
            } else { // 度为0的情况
                node->data = tmp->data;
                node->left = tmp->left;
                node->right = tmp->right;
                free(tmp);
                tree->count--;
            }
        } else { // 找到node的前驱节点
            tmp = node->left;
            while (tmp && tmp->right) {
                tmp = tmp->right;
            }
            node->data = tmp->data;
            node->left = deleteAVLNode(tree, node->left, tmp->data);
        }
    }
    // 更新节点的高度
    node->height = 1 + maxNum(h(node->left), h(node->right));
    // 计算平衡因子
    int balance = getBalance(node);

    // 根据平衡因子进行对应操作
    if (balance > 1) {
        if (getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
        }
        return rightRotate(node);
    } else if (balance < -1) {
        if (getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
        }
        return leftRotate(node);
    }

    return node;
}

/*从平衡二叉树中删除值为e的节点
 *1. 首先根据平衡二叉树的性质找到要删除的节点（如果没有找到直接返回空）
 *2. 判断要删除节点的度的数量
 *  2.1 如果度的数量为0，则直接删除并返回空
 *  2.2 如果度的数量为1，则删除节点，并将子节点返回
 *  2.3 如果度的数量为2，则找到其前驱或后继节点，返回其前驱或者后继节点
 *3. 更新节点的高度，归的过程中寻找失衡点
 *4. 根据LL，LR，RL，RR的规则对树进行旋转
*/

void deleteAVLTree(AVLTree *tree, Element e) {
    if (tree) {
        deleteAVLNode(tree, tree->root, e);
    }
}

