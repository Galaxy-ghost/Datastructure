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

# 并查集
add_executable(2-5UnionFindSet 02.TreeStruct/05.UnionFindSet/quickFindSet.c 02.TreeStruct/05.UnionFindSet/quickFindSet.h
                02.TreeStruct/05.UnionFindSet/quickUnionSet.c 02.TreeStruct/05.UnionFindSet/quickUnionSet.h 02.TreeStruct/05.UnionFindSet/main.c)

# 哈夫曼树
add_executable(2-6HuffmanTree 02.TreeStruct/06.HuffmanTree/huffmanTree.c 02.TreeStruct/06.HuffmanTree/huffmanTree.h
                02.TreeStruct/06.HuffmanTree/main.c)

# 图的邻接矩阵存储方式
add_executable(3-1MatrixGraph 03.Graph/01.MatrixGraph/matrixGraph.c 03.Graph/01.MatrixGraph/matrixGraph.h 03.Graph/01.MatrixGraph/main.c)

# 图的邻接表存储方式
add_executable(3-2AdjacentList 03.Graph/02.AdjacentList/adjacentList.c 03.Graph/02.AdjacentList/adjacentList.h 03.Graph/02.AdjacentList/main.c)

# 图的十字链表存储方式
add_executable(3-3CrossLinkGraph 03.Graph/03.CrossLinkGraph/crossLinkGraph.c 03.Graph/03.CrossLinkGraph/crossLinkGraph.h 03.Graph/03.CrossLinkGraph/main.c)

# 图的邻接多重表存储方式
add_executable(3-4AdjacencyMultiList 03.Graph/04.AdjacencyMultiList/adjacencyMultiList.c 03.Graph/04.AdjacencyMultiList/adjacencyMultiList.h 03.Graph/04.AdjacencyMultiList/main.c)

# Kruskal算法
add_executable(3-5Kruskal 03.Graph/05.MiniTree/Kruskal.c 03.Graph/05.MiniTree/Kruskal.h 03.Graph/05.MiniTree/main.c
                03.Graph/01.MatrixGraph/matrixGraph.c 03.Graph/01.MatrixGraph/matrixGraph.h)

# 拓扑排序
add_executable(3-6TopologicalSort 03.Graph/06.TopologicalSort/topologicalSort.c 03.Graph/06.TopologicalSort/topologicalSort.h 03.Graph/06.TopologicalSort/main.c
                03.Graph/02.AdjacentList/adjacentList.c 03.Graph/02.AdjacentList/adjacentList.h)

# 关键路径
add_executable(3-7KeyPath 03.Graph/07.KeyPath/keyPath.c 03.Graph/07.KeyPath/keyPath.h 03.Graph/07.KeyPath/main.c
                03.Graph/02.AdjacentList/adjacentList.c 03.Graph/02.AdjacentList/adjacentList.h)

# 插入排序
add_executable(4-1InsertSort 04.Sort/sortHelper.c 04.Sort/sortHelper.h 04.Sort/01.InsertSort/insertSort.c 04.Sort/01.InsertSort/insertSort.h 04.Sort/01.InsertSort/main.c)
