//
// Created by Galaxy. on 2023/1/8.
//

#ifndef DATASTRUCTURE_SQLIST_H
#define DATASTRUCTURE_SQLIST_H
/*
 * 动态顺序表，使用顺序存储，数据容量动态增加
 * 外部按照[1,n]的方式进行访问
 * 内部使用C语言实现，所以内部的索引从0开始
 */
typedef int Element;
typedef struct{
    Element  *elem;             // 顺序表元素空间的首地址
    int len;                    // 记录顺序表的元素个数
    int capacity;               // 记录顺序表的容量
}SqList;

SqList *createSqList(int n);        // 产生容量为n个元素的顺序表
void releaseSqList(SqList *seq);    // 释放这个顺序表
int getSqList(SqList *seq, int pos, Element *ele);      // 获取顺序表中某个位置的值
int locateSqList(SqList *seq, Element ele);             // 查找元素在顺序表中的位置
int insertSqList(SqList *seq, int pos, Element ele);    //在顺序表指定位置中插入元素
void showSqList(SqList *seq);                           // 显示顺序表中的元素
int deleteSqList(SqList *seq, int pos);                 // 从顺序表的指定位置删除元素

#endif //DATASTRUCTURE_SQLIST_H