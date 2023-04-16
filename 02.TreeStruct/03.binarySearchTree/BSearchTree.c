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

static void deleteMinNode(BSNode *node) {
    // 即找到节点的右子树的节点的最小值，并将它交换位置
    BSNode *mini = node->right;
    BSNode *pre = node;
    while (mini && mini->left) {
        pre = mini;
        mini = mini->left;
    }
    // 此时的mini节点一定指向了右子树的最小节点
    node->data = mini->data;
    if (pre->data == node->data) { // 说明最小值的节点就在node的right
        pre->right = mini->right;
    } else {
        pre->left = mini->right;
    }
    free(mini);
}

/* 1. 首先先找到待删除的节点，还需要一个pre指针指向待删除节点的前驱节点
*  2. 判断node的度的情况，根据度的情况进行不同的处理
*/
void deleteBSTreeNoRecur(BSTree *tree, Element e) {
    BSNode *node = tree->root;
    BSNode *pre = NULL;

    while (node) {
        if (node->data < e) {
            pre = node;
            node = node->right;
        } else if (node->data > e) {
            pre = node;
            node = node->left;
        }else {
            break;
        } 
    }
    // 经过上述操作，node指向的就是值为e的节点或是空节点
    // 空节点有两种情况，一种是树中没有元素，另一种是没有找到该元素，这两种情况我们都不用进行操作
    // 接下来要判断节点的度
    BSNode *tmp = NULL;
    if (pre && node) { // 找到了node节点且不是根节点
        if (node->left == NULL) {
            tmp = node->right;
        } else if (node->right == NULL) {
            tmp = node->left;
        } else { // 度为2的情况
            // 这里采用的方式是寻找node节点的后继节点，然后将后继节点与该节点进行交换
            deleteMinNode(node);
            tree->count--;
            return;
        }

        if (node->data > pre->data) {
            pre->right = tmp;
        } else {
            pre->left = tmp;
        }
        free(node);
        tree->count --;
        return ;
    }
    if (pre == NULL && node) {
        deleteMinNode(node);
        tree->count--;
    }
}

static BSNode *insertBSNodeRecur(BSTree *tree, BSNode *node, Element e) {
    if (node == NULL) {
        return createBNode(e);
    }
    if (e < node->data) {
       node->left = insertBSNodeRecur(tree, node->left, e); 
    } else if (e > node->data) {
        node->right = insertBSNodeRecur(tree, node->right, e);
    }
    
    return node;
}

void insertBSTreeRecur(BSTree *tree, Element e) {
    tree->root = insertBSNodeRecur(tree, tree->root, e);
}


int getBSNodeDepth(BSNode *node) {
     if (node == NULL) {
        return 0;
    }   
    int leftHeight = getBSNodeDepth(node->left);
    int rightHeight = getBSNodeDepth(node->right);

    if (leftHeight > rightHeight) {
        return ++leftHeight;
    } else {
        return ++rightHeight;
    }
}

// 找到以node为根节点的子树中最小值的节点
static BSNode *MinValueBSNode(BSNode *node) {
    while (node && node->left) {
        node = node->left;
    }
    return node;
} 


static BSNode *deleteBSNode(BSTree *tree, BSNode *node, Element e) {
    if (node == NULL) {
        return NULL;
    }
    if (e < node->data) {
        node->left = deleteBSNode(tree, node->left, e);
    } else if (e > node->data) {
        node->right = deleteBSNode(tree, node->right, e);
    } else { // 这时候已经找到了要删除的节点
       // 与非递归方式一样，要判断度的数量来进行删除节点
        BSNode *tmp;
        if (node->left == NULL) {
            tmp = node->right;
            tree->count--;
            free(node);
            return tmp;
        } else if (node->right == NULL) {
            // 与之前非递归方式的分析类似，不管是度为1还是度为0，只要知道其中一个孩子为空
            // 则直接删除节点，并将另一个孩子赋值给前驱节点
            tmp = node->left;
            tree->count--;
            free(node);
            return tmp;
        } else { // 这是度为2的情况，这时候要删除右孩子中的最小值的节点
            tmp = MinValueBSNode(node->right);
            node->data = tmp->data;
            deleteBSNode(tree, node->right, tmp->data);
        }
    }
    return node;
}

void deleteBSTreeRecur(BSTree *tree, Element e) {
    if (tree) {
        tree->root = deleteBSNode(tree, tree->root, e);
    }
}

