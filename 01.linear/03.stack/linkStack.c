//
// Created by Galaxy. on 2023/1/11.
//

#include "linkStack.h"

LinkStack *createLinkStack() {
    LinkStack  *stack = (LinkStack *) malloc(sizeof(LinkStack));
    if(stack == NULL){
        printf("malloc error!\n");
        return NULL;
    }
    stack->count = 0;
    stack->top = NULL;
    return stack;
}

int pushLinkStack(LinkStack *stack, Element e) {
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    if(node == NULL) {
        printf("malloc error!\n");
        return -1;
    }
    node->data = e;
    node->next = stack->top;
    stack->top = node;
    stack->count++;
    return 0;
}

int popLinkStack(LinkStack *stack, Element *e) {
    if(stack->top == NULL){
        printf("stack empty!\n");
        return -1;
    }
    *e = stack->top->data;
    StackNode *tmp = stack->top;
    stack->top = stack->top->next;
    stack->count--;
    free(tmp);
    return 0;
}

void releaseLinkStack(LinkStack *stack) {
    if(stack){
        while(stack->top){
            StackNode *tmp = stack->top;
            stack->top = stack->top->next;
            free(tmp);
            stack->count--;
        }
        free(stack);
    }
}



