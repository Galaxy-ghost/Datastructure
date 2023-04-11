//
// Created by Galaxy. on 2023/1/11.
//

#ifndef DATASTRUCTURE_LINKSTACK_H
#define DATASTRUCTURE_LINKSTACK_H

/*
 * 链式存储栈，关注节点结构，栈的操作结构
 */
#include "commom.h"
// 节点结构
typedef struct stackNode {
    Element data;
    struct stackNode *next;
}StackNode;
// 表头结构
typedef struct {
    StackNode *top;
    int count;              // 统计链栈里元素的数量
}LinkStack;

LinkStack *createLinkStack();                       // 创建新的链栈
void releaseLinkStack(LinkStack *stack);            // 释放链栈
int pushLinkStack(LinkStack *stack, Element e);     // 元素入栈
int popLinkStack(LinkStack *stack, Element *e);     // 元素出栈

#endif //DATASTRUCTURE_LINKSTACK_H