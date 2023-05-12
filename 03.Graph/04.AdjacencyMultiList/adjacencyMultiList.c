//
// Created by Galaxy. on 2023/5/11.
//

#include "adjacencyMultiList.h"

#include <stdio.h>
#include <stdlib.h>

AdjacencyMultiList* createMultiList(int n)
{
    AdjacencyMultiList* graph = (AdjacencyMultiList*) malloc(sizeof(AdjacencyMultiList));
    if (graph == NULL) {
        fprintf(stderr, "malloc error!\n");
        return NULL;
    }
    graph->nodes = (MultiListVertex*) malloc(sizeof(MultiListVertex) * n);
    graph->numVertex = n;
    graph->numEdge = 0;
    return graph;
}

void releaseMultiList(AdjacencyMultiList* graph)
{
    if (graph) {
        if (graph->nodes) {
            for (int i = 0; i < graph->numVertex; i++) {
                MultiListEdge* edge = graph->nodes[i].firstEdge;
                MultiListEdge* tmp;
                while (edge) {
                    tmp = edge;
                    int j;
                    if (edge->iVex == i)
                        edge = edge->iNext, j = edge->jVex;
                    else
                        edge = edge->jNext, j = edge->iVex;
                    deleteMultiListEdge(graph, i, j);
                }
            }
        }
        free(graph->nodes);
    }
    free(graph);
}

void initMultiList(AdjacencyMultiList* graph, char* names[], int num)
{
    for (int i = 0; i < num; i++) {
        graph->nodes[i].no = i;
        graph->nodes[i].name = names[i];
        graph->nodes[i].firstEdge = NULL;
    }
}

void insertMultiListEdge(AdjacencyMultiList* graph, int a, int b, int w)
{
    MultiListEdge* edge = (MultiListEdge*) malloc(sizeof(MultiListEdge));
    edge->weight = w;
    edge->iVex = a;
    edge->iNext = graph->nodes[a].firstEdge;
    graph->nodes[a].firstEdge = edge;
    // 用同样的方法处理b节点，使用头插法
    edge->jVex = b;
    edge->jNext = graph->nodes[b].firstEdge;
    graph->nodes[b].firstEdge = edge;
    graph->numEdge++;
}

int deleteMultiListEdge(AdjacencyMultiList* graph, int a, int b)
{
    // 找到按照节点a顺序处理的前一个节点
    MultiListEdge* aPreEdge = NULL;
    MultiListEdge* aCurEdge = graph->nodes[a].firstEdge;
    while (aCurEdge
           && (!(aCurEdge->iVex == a && aCurEdge->jVex == b)
               || !(aCurEdge->iVex == b && aCurEdge->jVex == a))) {
        aPreEdge = aCurEdge;
        if (aCurEdge->iVex == a) {
            aCurEdge = aCurEdge->iNext;
        }
        else {
            aCurEdge = aCurEdge->jNext;
        }
    }
    if (aCurEdge == NULL) {
        return -1;
    }
    // 继续寻找b路径上的前一个节点
    MultiListEdge* bPreEdge = NULL;
    MultiListEdge* bCurEdge = graph->nodes[b].firstEdge;
    while (bCurEdge
           && (!(bCurEdge->iVex == b && bCurEdge->jVex == a)
               || !(bCurEdge->iVex == a && bCurEdge->jVex == b))) {
        bPreEdge = bCurEdge;
        if (bCurEdge->iVex == b) {
            bCurEdge = bCurEdge->iNext;
        }
        else {
            bCurEdge = bCurEdge->jNext;
        }
    }
    if (bCurEdge == NULL) {
        return -1;
    }
    // 先进行a节点路径上的删除
    if (aPreEdge == NULL) {
        if (aCurEdge->iVex == a)
            graph->nodes[a].firstEdge = aCurEdge->iNext;
        else
            graph->nodes[a].firstEdge = aCurEdge->jNext;
    }
    else {
        if (aPreEdge->iVex == a) {
            if (aCurEdge->iVex == a)
                aPreEdge->iNext = aCurEdge->iNext;
            else
                aPreEdge->iNext = aCurEdge->jNext;
        }
        else {
            if (aCurEdge->iVex == a)
                aPreEdge->jNext = aCurEdge->iNext;
            else
                aPreEdge->jNext = aCurEdge->jNext;
        }
    }

    if (bPreEdge == NULL) {
        if (bCurEdge->iVex == b)
            graph->nodes[b].firstEdge = bCurEdge->iNext;
        else
            graph->nodes[b].firstEdge = bCurEdge->jNext;
    }
    else {
        if (bPreEdge->iVex == b) {
            if (bCurEdge->iVex == b)
                bPreEdge->iNext = bCurEdge->iNext;
            else
                bPreEdge->iNext = bCurEdge->jNext;
        }
        else {
            if (bCurEdge->iVex == b)
                bPreEdge->jNext = bCurEdge->iNext;
            else
                bPreEdge->jNext = bCurEdge->jNext;
        }
    }

    return 0;
}
