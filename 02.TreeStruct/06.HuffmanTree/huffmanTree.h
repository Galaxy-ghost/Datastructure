//
// Created by Galaxy. on 2023/4/22.
//

#ifndef DATASTRUCTURE_HUFFMANTREE_H
#define DATASTRUCTURE_HUFFMANTREE_H

/* huffman树表示的是树中各节点带权路径的最小值
*  这里采用顺序存储方式来存储huffman树
*  当具有n个元素时（叶子节点），哈夫曼树的总节点个数为2n - 1
*  这里规定下标为0的索引不使用，所以在申请内存的时候直接申请2n个内存空间
*/

typedef struct {
    int weight; // 权重
    int lChild, rChild; // 哈夫曼树的左孩子和右孩子，这里使用的是int类型，指向是孩子节点的下标（索引） 
    int parent; // 指向父亲节点的索引
}HuffmanNode, *HuffmanTree;

// 构建HuffmanTree，w为权值数组，n为节点个数
HuffmanTree createHuffmanTree(const int *w, int n);
void releaseHuffmanTree(HuffmanTree tree); // 释放HuffmanTree

typedef char * HuffmanCode;
// 根据哈夫曼树产生哈夫曼编码
HuffmanTree *createHuffmanCode(HuffmanTree tree, int n);
void releaseHuffmanCode(HuffmanCode *codes, int n);

#endif //DATASTRUCTURE_HUFFMANTREE_H
