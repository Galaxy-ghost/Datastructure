cmake_minimum_required(VERSION 3.24)
project(DataStructure C)

set(CMAKE_C_STANDARD 11)

add_executable(DataStructure main.c)

# 线性顺序存储表
add_executable(1-1seqList 01.linear/01.seqList/sqList.c 01.linear/01.seqList/sqList.h 01.linear/01.seqList/main.c 02.TreeStruct/01.binaryTree/binaryTree.c 02.TreeStruct/01.binaryTree/binaryTree.h)

# 单向链表
add_executable(1-2linkList 01.linear/02.linkList/linkList.c 01.linear/02.linkList/linkList.h 01.linear/02.linkList/main.c)

# 顺序栈与链式栈
add_executable(1-3stack 01.linear/03.stack/main.c 01.linear/03.stack/arrayStack.c 01.linear/03.stack/arrayStack.h 01.linear/03.stack/linkStack.c 01.linear/03.stack/linkStack.h 01.linear/03.stack/commom.h)

# 顺序队列（循环队列）与链式队列
add_executable(1-4queue 01.linear/04.queue/arrayQueue.c 01.linear/04.queue/arrayQueue.h 01.linear/04.queue/linkQueue.c 01.linear/04.queue/linkQueue.h 01.linear/04.queue/main.c 01.linear/04.queue/common.h)

# 二叉树链式存储
add_executable(2-1binaryTree 02.TreeStruct/01.binaryTree/binaryTree.c 02.TreeStruct/01.binaryTree/binaryTree.h
                02.TreeStruct/01.binaryTree/arrayQueue.c 02.TreeStruct/01.binaryTree/arrayQueue.h
                02.TreeStruct/01.binaryTree/arrayStack.c 02.TreeStruct/01.binaryTree/arrayStack.h
                02.TreeStruct/01.binaryTree/main.c)
# 线索二叉树
add_executable(2-2threaderTree 02.TreeStruct/02.threadedTree/threadedBTree.c 02.TreeStruct/02.threadedTree/threadedBTree.h 02.TreeStruct/02.threadedTree/main.c)

# 二叉搜索树
add_executable(2-3binarySearchTree 02.TreeStruct/03.binarySearchTree/BSearchTree.c 02.TreeStruct/03.binarySearchTree/BSearchTree.h 02.TreeStruct/03.binarySearchTree/main.c)

# AVL树
add_executable(2-4AVLTree 02.TreeStruct/04.AVLTree/avlTree.c 02.TreeStruct/04.AVLTree/avlTree.h 02.TreeStruct/04.AVLTree/main.c)