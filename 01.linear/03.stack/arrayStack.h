//
// Created by Galaxy. on 2023/1/11.
//

#ifndef DATASTRUCTURE_ARRAYSTACK_H
#define DATASTRUCTURE_ARRAYSTACK_H

/*
 * 顺序栈 满递增栈
 */
#include "commom.h"
#define MaxStackSize 5
typedef struct {
    Element data[MaxStackSize];
    int top;
}ArrayStack;

ArrayStack *createArrayStack();                     // 创建一个新栈
void releaseArrayStack(ArrayStack *stack);          // 释放一个栈
int pushArrayStack(ArrayStack *stack, Element e);   // 将一个指定的元素入栈
int popArrayStack(ArrayStack *stack,Element *e);    // 出栈

#endif //DATASTRUCTURE_ARRAYSTACK_H
