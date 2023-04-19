//
// Created by Galaxy. on 2023/4/19.
//

#ifndef DATASTRUCTURE_QUICKFINDSET_H
#define DATASTRUCTURE_QUICKFINDSET_H
/* 并查集的quickfinset算法下的结构定义
*  每个元素都存有一个编号，只要编号一样，就代表两个元素是一个集合中的人
*  如果要合并，就是将一个集团中所有元素的编号改为另一个集团的编号
*/
typedef int Element;

typedef struct {
    Element *data; // 用来存储元素
    int n; // 并查集中的元素个数量
    int *groupID; // 每个元素的对应的索引编号
}QuickFindSet;

// 创建一个含有n个元素的并查集
QuickFindSet *createQuickFindSet(int n);
// 释放并查集结构
void releaseQuickFindSet(QuickFindSet *setQF);
// 初始化并查集，设置元素值和对应的编号
void initQuickFindSet(QuickFindSet *setQF, const Element *data, int n);
// 查：判断两个元素是不是同一组id
int isSameQF(QuickFindSet *setQF, Element a, Element b);
// 并：合并两个元素
void unionQF(QuickFindSet *setQF, Element a, Element b);

#endif //DATASTRUCTURE_QUICKFINDSET_H
