//
// Created by Galaxy. on 2023/1/10.
//

#ifndef DATASTRUCTURE_LINKLIST_H
#define DATASTRUCTURE_LINKLIST_H
/*
 * 单向链表，带头节点的表头
 */
typedef int Element;
// 节点
typedef struct node{
    Element ele;
    struct node *next;
}Node;
// 带头节点的表头
typedef struct{
    Node head;
    int len;
}LinkList;

LinkList *createLinkList();                 // 初始化单链表
void releaseLinkList(LinkList *linkList);   // 释放单链表
int insertLinkList(LinkList *linkList, int pos, Element e); // 向单链表的指定位置插入指定元素
int deleteLinkList(LinkList *linkList, Element e);          // 删除单链表中指定的一个元素
void showLinkList(LinkList *linkList);                      // 遍历输出单链表中的元素

#endif //DATASTRUCTURE_LINKLIST_H
