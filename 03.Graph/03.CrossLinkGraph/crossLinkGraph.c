//
// Created by Galaxy. on 2023/5/11.
//

#include "crossLinkGraph.h"
#include <stdio.h>
#include <stdlib.h>

CrossGraph* createCrossGraph(int n) {
    CrossGraph *graph = (CrossGraph *)malloc(sizeof (CrossGraph));
    if (graph == NULL) {
        fprintf(stderr, "malloc error!\n");
        return NULL;
    }
    graph->nodes = (CrossVertex *)malloc(sizeof(CrossVertex) * n);
    graph->numVertex = n;
    graph->numEdge = 0;
    return graph;
}

void releaseCrossGraph(CrossGraph* graph) {
    if (graph) {
        if (graph->nodes) {
            for (int i = 0; i < graph->numVertex; i++) {
                ArcBox *box = graph->nodes[i].firstOut;
                ArcBox *tmp;
                while (box) {
                    tmp = box;
                    box = box->tailNext;
                    free(tmp);
                }
            }
        }
        free(graph->nodes);
    }
    free(graph);
}

void initCrossGraph(CrossGraph* graph, char* names[], int num) {
    for (int i = 0; i < num; i++) {
        graph->nodes[i].no = i;
        graph->nodes[i].show = names[i];
        graph->nodes[i].firstOut = NULL;
        graph->nodes[i].firstIn = NULL;
    }
}

void addCrossArc(CrossGraph* graph, int tail, int head, int w) {
    ArcBox *box = (ArcBox *) malloc(sizeof(ArcBox));
    box->weight = w;
    // 使用头插法
    box->tailVertex = tail;
    box->tailNext = graph->nodes[tail].firstOut;
    graph->nodes[tail].firstOut = box;
    box->headVertex = head;
    box->headNext = graph->nodes[head].firstIn;
    graph->nodes[head].firstIn = box;
}

// 计算出度的数量
int outDegreeCrossGraph(CrossGraph *graph, int no) {
    int count = 0;
    ArcBox *box = graph->nodes[no].firstOut;
    while (box) {
        count++;
        box = box->tailNext;
    }
    return count;
}

// 计算入度的数量
int inDegreeCrossGraph(CrossGraph *graph, int no) {
    int count = 0;
    ArcBox *box = graph->nodes[no].firstIn;
    while (box) {
        count++;
        box = box->headNext;
    }
    return count;
}








