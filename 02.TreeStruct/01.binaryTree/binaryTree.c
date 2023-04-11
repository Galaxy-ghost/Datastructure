//
// Created by Galaxy. on 2023/1/19.
//

#include "binaryTree.h"
#include "arrayQueue.h"
#include "arrayStack.h"

BinaryTree *createBinaryTree(TreeNode *root) {
    BinaryTree *tree = (BinaryTree *)malloc(sizeof(BinaryTree));
    if (tree == NULL){
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

static void releaseTreeNode(BinaryTree *tree, TreeNode *node) {
    if (node) {
        releaseTreeNode(tree, node->left);
        releaseTreeNode(tree, node->right);
        free(node);
        tree->count--;
    }
}

/*
 * 释放二叉树，通过后序遍历的方式将节点逐个释放
 */
void releaseBinaryTree(BinaryTree *tree){
    if(tree) {
        releaseTreeNode(tree, tree->root);
        printf("tree has %d node!\n", tree->count);
        free(tree);
    }
}

/*
 * 初始化新节点的左右指针指向空
 */
TreeNode *createTreeNode(Element e) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    if (node == NULL) {
        fprintf(stderr, "tree node malloc error!\n");
        return NULL;
    }
    node->data = e;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/*
 * 向父节点插入左右节点
 */
void insertBinaryTree(BinaryTree *tree, TreeNode *parent, TreeNode *left, TreeNode *right) {
    if (tree && parent) {
        parent->left = left;
        parent->right = right;
        if (parent->left) {
            tree->count++;
        }
        if (parent->right) {
            tree->count++;
        }
    }
}

static void preOrder(TreeNode *node) {
    if (node) {
        visitTreeNode(node);
        preOrder(node->left);
        preOrder(node->right);
    }
}

static void inOrder(TreeNode *node) {
    if (node) {
        inOrder(node->left);
        visitTreeNode(node);
        inOrder(node->right);
    }
}

static void postOrder(TreeNode *node) {
    if (node) {
        postOrder(node->left);
        postOrder(node->right);
        visitTreeNode(node);
    }
}

/*
 * 访问节点
 */
void visitTreeNode(TreeNode *node) {
    printf("\t%c",node->data);
}

/*
 * 先序遍历
 */
void preOrderBTreeRecur(BinaryTree *tree) {
    if (tree) {
        preOrder(tree->root);
    }
}

/*
 * 中序遍历
 */
void inOrderBTreeRecur(BinaryTree *tree) {
    if (tree) {
        inOrder(tree->root);
    }
}

/*
 * 后序遍历
 */
void postOrderBTreeRecur(BinaryTree *tree) {
    if (tree) {
        postOrder(tree->root);
    }
}

/*
 * 层序遍历
 */
void levelOrderBTree(BinaryTree *tree) {
    ArrayQueue * queue = createArrayQueue();
    pTreeNode node;
    enterArrayQueue(queue, tree->root);
    while (deleteArrayQueue(queue, &node) != -1) {
        visitTreeNode(node);
        if(node->left) {
            enterArrayQueue(queue, node->left);
        }
        if(node->right) {
            enterArrayQueue(queue, node->right);
        }
    }
    releaseArrayQueue(queue);
}

/* 非递归的先序遍历
 * 1. 压入根节点
 * 2. 弹出元素，访问
 * 3. 将元素的右边先压栈，再将左边压栈
 */
void preOrderBTreeNoRecur(BinaryTree *tree) {
    TreeNode *node;
    if (tree) {
        ArrayStack *stack = createArrayStack();
        pushArrayStack(stack, tree->root);
        while (popArrayStack(stack, &node) != -1 && node) {
            visitTreeNode(node);
            if (node->right) {
                pushArrayStack(stack, node->right);
            }
            if (node->left) {
                pushArrayStack(stack, node->left);
            }
        }
        releaseArrayStack(stack);
    }
}

/* 非递归的中序遍历
 * 1. 从根节点，整条左边进栈
 * 2. 从栈中弹出节点访问，然后以这个节点的右孩子为新节点
 * 3. 再次安排整条左边进栈，再弹栈
 */
void inOrderBTreeNoRecur(BinaryTree *tree) {
    TreeNode *node;
    if (tree) {
        ArrayStack *stack = createArrayStack();
        node = tree->root;
        while (stack->top >= 0 || node) {
            if (node) {
                pushArrayStack(stack, node);
                node = node->left;
            } else {
                popArrayStack(stack, &node);
                visitTreeNode(node);
                node = node->right;
            }
        }
        releaseArrayStack(stack);
    }
}

/* 非递归的后序遍历，需要两个栈，第一个栈作为辅助，第二个栈来输出
 * 1. 第一个栈压入根节点后，弹出到第二个栈，这样根节点就变成最后输出
 * 2. 后序遍历的倒数第二个元素应该是根节点的右孩子，所以辅助栈先左后右
 * 3. 辅助栈弹出元素，放入到第二个栈，这个节点先左后右放入第一个栈
 */
void postOrderBTreeNoRecur(BinaryTree *tree) {
    TreeNode *node;
    if (tree) {
        ArrayStack *stack1 = createArrayStack();
        ArrayStack *stack2 = createArrayStack();
        pushArrayStack(stack1, tree->root);
        while (popArrayStack(stack1, &node) != -1) {
            pushArrayStack(stack2, node);
            if (node->left) {
                pushArrayStack(stack1, node->left);
            }
            if (node->right) {
                pushArrayStack(stack1, node->right);
            }
        }
        while (popArrayStack(stack2, &node) != -1) {
            visitTreeNode(node);
        }
        releaseArrayStack(stack1);
        releaseArrayStack(stack2);
    }
}

