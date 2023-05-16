//
// Created by Galaxy. on 2023/5/12.
//

#include "Kruskal.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int initEdgeSet(const MGraph *graph, EdgeSet *edges) {
    int k =  0;
    for (int i = 0; i < graph->nodeNum; i++) {
        for (int j = i + 1; j < graph->nodeNum; j++) {
            if (graph->edge[i][j] > 0) {
                edges[k].begin = i;
                edges[k].end = j;
                edges[k].weight = graph->edge[i][j];
                k++;
            }
        }
    }
    return k;
}

void sortEdgeSet(EdgeSet *edges, int num) {
    EdgeSet tmp;
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if (edges[j].weight < edges[i].weight) {
                memcpy(&tmp, &edges[i], sizeof(EdgeSet));
                memcpy(&edges[i], &edges[j], sizeof(EdgeSet));
                memcpy(&edges[j], &tmp, sizeof(EdgeSet));
            }
        }
    }
}

static int getRoot(int *uSet, int p) {
    while (p != uSet[p]) {
        p = uSet[p];
    }
    return p;
}

int KruskalMGraph(const MGraph *graph, const EdgeSet *edges, int num, EdgeSet *result) {
    int k = 0;
    int count = 0;
    int sum = 0;
    int *uSet = (int *)malloc(sizeof(int) * (graph->nodeNum - 1));
    for (int i = 0; i < graph->nodeNum; i++) {
        uSet[i] = i;
    }

    for (int i = 0; i < num; i++) {
        int a = getRoot(uSet, edges[i].begin);
        int b = getRoot(uSet, edges[i].end);
        if (a != b) {
            uSet[a] = b;
            result[k].begin = edges[i].begin;
            result[k].end = edges[i].end;
            result[k].weight = edges[i].weight;
            k++;
            count++;
            sum += edges[i].weight;
        }
    }

    free(uSet);
    return sum;
}
