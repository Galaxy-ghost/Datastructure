//
// Created by Galaxy. on 2023/1/11.
//

#include "arrayStack.h"
#include <stdio.h>
#include <stdlib.h>

ArrayStack *createArrayStack() {
    ArrayStack *stack = (ArrayStack *)malloc(sizeof(ArrayStack));
    if(stack == NULL) {
        printf("malloc error!\n");
        return NULL;
    }
    stack->top = -1;
    return stack;
}

void releaseArrayStack(ArrayStack *stack) {
    if (stack){
        free(stack);
    }
}

/*
 * 数据存放位置[0,max - 1]
 */
int pushArrayStack(ArrayStack *stack, Element e) {
    // 先考虑上溢出的问题
    if(stack->top + 1 > MaxStackSize - 1){
        printf("Overflow!\n");
        return -1;
    }
    stack->data[++stack->top] = e;
    return 0;
}

int popArrayStack(ArrayStack *stack, Element *e) {
    // 解决下溢出的问题
    if(stack->top < 0){
        printf("Underflow!\n");
        return -1;
    }
    *e = stack->data[stack->top--];
    return 0;
}


