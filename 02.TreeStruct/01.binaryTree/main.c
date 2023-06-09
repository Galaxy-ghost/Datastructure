//
// Created by Galaxy. on 2023/1/19.
//
#include "binaryTree.h"

BinaryTree *initTree1() {
    TreeNode *nodeA = createTreeNode('A');
    TreeNode *nodeB = createTreeNode('B');
    TreeNode *nodeC = createTreeNode('C');
    TreeNode *nodeD = createTreeNode('D');
    TreeNode *nodeE = createTreeNode('E');
    TreeNode *nodeF = createTreeNode('F');
    TreeNode *nodeG = createTreeNode('G');
    TreeNode *nodeH = createTreeNode('H');
    TreeNode *nodeK = createTreeNode('K');

    BinaryTree *tree = createBinaryTree(nodeA);
    insertBinaryTree(tree, nodeA, nodeB, nodeE);
    insertBinaryTree(tree, nodeB, NULL, nodeC);
    insertBinaryTree(tree, nodeE, NULL, nodeF);
    insertBinaryTree(tree, nodeC, nodeD, NULL);
    insertBinaryTree(tree, nodeF, nodeG, NULL);
    insertBinaryTree(tree, nodeG, nodeH, nodeK);
    return tree;
}

int main() {
    BinaryTree *tree = initTree1();
    printf("preOrder: ");
    preOrderBTreeRecur(tree);
    printf("\n");
    printf("inOrder: ");
    inOrderBTreeRecur(tree);
    printf("\n");
    printf("postOrder: ");
    postOrderBTreeRecur(tree);
    printf("\n");
    printf("levelOrder: ");
    levelOrderBTree(tree);
    printf("\n");
    printf("preOrderNoRecur: ");
    preOrderBTreeNoRecur(tree);
    printf("\n");
    printf("inOrderNoRecur: ");
    inOrderBTreeNoRecur(tree);
    printf("\n");
    printf("postOrderNoRecur: ");
    postOrderBTreeNoRecur(tree);
    printf("\n");
    releaseBinaryTree(tree);
    return 0;
}
