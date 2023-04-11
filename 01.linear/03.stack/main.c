//
// Created by Galaxy. on 2023/1/11.
//

#include <stdio.h>
#include "arrayStack.h"
#include "linkStack.h"

int test01(){
    ArrayStack * stack = createArrayStack();
    Element e;
    if(stack == NULL){
        printf("malloc error!\n");
        return -1;
    }
    for(int i = 0; i < 5; ++i){
        pushArrayStack(stack, i + 100);
    }
    pushArrayStack(stack, 500);
    printf("pop:");
    for (int i = 0; i < 5; ++i) {
        popArrayStack(stack, &e);
        printf("\t%d",e);
    }
    releaseArrayStack(stack);
    return 0;
}

int test02(){
    LinkStack *stack = createLinkStack();
    Element e;
    if(stack == NULL){
        printf("malloc error!\n");
        return -1;
    }
    for(int i = 0; i < 5;i++){
        pushLinkStack(stack, i + 100);
    }
    printf("pop:");
    for(int i = 0; i < 5;i++){
        popLinkStack(stack, &e);
        printf("\t%d",e);
    }
    releaseLinkStack(stack);
}


int main(){
    test02();
    return 0;
}