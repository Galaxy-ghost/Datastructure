//
// Created by Galaxy. on 2023/5/15.
//

#include "topologicalSort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TopologicalSort(AGraph *graph) {
    int *inDegree;
    // 1. 首先为入度表申请一个空间
    inDegree = (int *) malloc(sizeof(int) * graph->nodeNum);
    if (inDegree == NULL) {
        return -1;
    }
    memset(inDegree, 0, sizeof(int) * graph->nodeNum);
    // 遍历每个节点，对入度表进行更新
    for (int i = 0; i < graph->nodeNum; i++) {
        if (graph->nodes[i].first) {
            ArcEdge *edge = graph->nodes[i].first;
            while (edge) {
                ++inDegree[edge->no];
                edge = edge->next;
            }
        }
    }
    // 根据入度表中的数据，将入度为0的点入栈
    int *stack;
    int top = -1;
    int count = 0; // 用来记录入栈的节点
    stack = (int *)malloc(sizeof (int) * graph->nodeNum);
    if (stack == NULL) {
        free(inDegree);
        return -1;
    }
    for (int i = 0; i < graph->nodeNum; i++) {
        if (inDegree[i] == 0) {
            stack[++top] = i;
        }
    }
    // 根据栈中的数据，弹出第一个任务，并将任务的出边删除
    // 根据删除的出边对入度表进行更新，然后再将入度为0的点入栈，直到最终没有边可以弹出
    while (top != -1) {
        int index = stack[top--];
        count++;
        visitAGraphNode(&graph->nodes[index]);
        if (graph->nodes[index].first) {
            ArcEdge *edge = graph->nodes[index].first;
            while (edge) {
                inDegree[edge->no] --;
                if (inDegree[edge->no] == 0) {
                    stack[++top] = edge->no;
                }
                edge = edge->next;
            }
        }
    }
    free(inDegree);
    free(stack);
    // 执行结束，根据count的值判断是否含有环
    if (count == graph->nodeNum) {
        return 0;
    } else {
        return 1;
    }
}

