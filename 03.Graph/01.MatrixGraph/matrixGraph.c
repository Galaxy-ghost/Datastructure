//
// Created by Galaxy. on 2023/4/27.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "matrixGraph.h"

int isEdge(int weight) {
    if (weight > 0 && weight < INF) {
        return 1;
    }
    return 0;
}


void initGraph(MGraph *g, int num, char *names[], int directed, int edgeValue) {
    g->directed = directed;
    g->nodeNum = num;
    g->edgeNum = 0;
    memset(g->vex, 0, sizeof(g->vex));
    memset(g->edge, 0, sizeof (MatrixEdge) * MaxNodeNum *MaxNodeNum);
    // 初始化顶点
    for (int i = 0; i < num; i++) {
        g->vex[i].no = i;
        g->vex[i].show = names[i];
        // 初始化边
        for (int j = 0; j < num; j++) {
            g->edge[i][j] = edgeValue;
        }
    }
}

void addMGraphEdge(MGraph *g, int x, int y, int w) {
    if (x < 0 || x > g->nodeNum) {
        return ;
    }
    if (y < 0 || y > g->nodeNum) {
        return ;
    }
    if (!isEdge(g->edge[x][y])) {
        g->edge[x][y] = w;
        if (g->directed == 0) {
            g->edge[y][x] = w;
        }
        g->edgeNum++;
    }
}
