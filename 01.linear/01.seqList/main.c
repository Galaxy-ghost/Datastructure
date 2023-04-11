//
// Created by Galaxy. on 2023/1/8.
//

#include "sqList.h"
#include <stdio.h>

int main(){
    int n = 5;
    SqList *seq = createSqList(n);
    for(int i = 0; i < n; i++){
        insertSqList(seq, i + 1, i + 100);
    }
    showSqList(seq);
    insertSqList(seq, 3, 300);
    showSqList(seq);
    printf("==========\n");
    deleteSqList(seq,3);
    showSqList(seq);
    return 0;
}