//
// Created by Galaxy. on 2023/5/7.
//

#include "adjacentList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


AGraph *createAGraph(int n) {
    AGraph *graph = (AGraph *)malloc(sizeof(AGraph));
    if (graph == NULL) {
        fprintf(stderr, "malloc error!\n");
        return NULL;
    }
    graph->edgeNum = 0;
    graph->nodeNum = n;
    graph->nodes = (ArcNode *)malloc(sizeof(ArcNode) * n);
    if (graph->nodes == NULL) {
        fprintf(stderr, "malloc node failed!\n");
        free(graph);
        return NULL;
    }
    memset(graph->nodes, 0, sizeof(ArcNode) * n);
    return graph;
}  

void releaseAGraph(AGraph *g) {
    ArcEdge *tmp;
    int count = 0;
    if (g) {
        for (int i = 0; i < g->nodeNum; i++) {
            ArcEdge *edge = g->nodes[i].first;
            while (edge) {
                tmp = edge;
                edge = edge->next;
                free(tmp);
                count++;
            }
        }
        printf("release %d edges\n", count);
        free(g);
    }
}

void initAGraph(AGraph *g, int num, char *names[], int directed) {
    g->directed = directed;
    for (int i = 0; i < num; i++) {
        g->nodes[i].no = i;
        g->nodes[i].show = names[i];
        g->nodes[i].first = NULL;
    }
}

static ArcEdge *createArcEdge(int y, int weight) {
    ArcEdge *edge = (ArcEdge *)malloc (sizeof(ArcEdge));
    edge->no = y;
    edge->weight = weight;
    edge->next = NULL;
    return edge;
}


void addAGraphEdge(AGraph *g, int x, int y, int w) {
    if (x < 0 || x >= g->nodeNum || y < 0 || y >= g->nodeNum) {
        return;
    }
    // 使用头插法
    if (x == y) {
        return;
    }
    ArcEdge *edge = createArcEdge(y, w);
    edge->next = g->nodes[x].first;
    g->nodes[x].first = edge;
    g->edgeNum++;
    if (g->directed == 0) {
        ArcEdge *edge = createArcEdge(w, w);
        edge->next = g->nodes[y].first;
        g->nodes[y].first = edge;
        g->edgeNum++;
    }
}
