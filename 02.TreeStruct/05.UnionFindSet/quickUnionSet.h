//
// Created by Galaxy. on 2023/4/19.
//

#ifndef DATASTRUCTURE_QUICKUNIONSET_H
#define DATASTRUCTURE_QUICKUNIONSET_H
/* 并查集下的QuickUnionSet结构 
* 每个元素都存有其父节点的编号  
*/
typedef int Element;

typedef struct {
    Element *data;
    int n;
    int *parent;
    int *size; // 实际工程中size优化和rank优化最终与不优化区别不大，取其一即可
}QuickUnionSet;

QuickUnionSet *createQuickUnionSet(int n); // 创建一个数量为n的并查集
void releaseQuickUnionSet(QuickUnionSet *setQU); // 释放一个并查集
void initQuickUnionSet(QuickUnionSet *setQU, const Element *data, int n);  // 初始化一个并查集
int isSameQU(QuickUnionSet *setQU, Element a, Element b); // 查：判断两个元素是否是一个集团
void unionQU(QuickUnionSet *setQU, Element a, Element b);  // 并：合并两个元素

#endif //DATASTRUCTURE_QUICKUNIONSET_H
