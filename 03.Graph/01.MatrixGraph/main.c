//
// Created by Galaxy. on 2023/4/27.
//
#include "matrixGraph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void setupMatrixGraph(MGraph *g1) {
    char *nodename[] = {"V1", "V2", "V3", "V4", "V5", "V6", "V7", "V8"};
    initGraph(g1, 8, nodename, 0, 0);
    addMGraphEdge(g1, 0, 1, 1);
	addMGraphEdge(g1, 0, 2, 1);
	addMGraphEdge(g1, 1, 3, 1);
	addMGraphEdge(g1, 1, 4, 1);
	addMGraphEdge(g1, 2, 5, 1);
	addMGraphEdge(g1, 2, 6, 1);
	addMGraphEdge(g1, 3, 7, 1);
	addMGraphEdge(g1, 4, 7, 1);
	addMGraphEdge(g1, 5, 6, 1);
}

int main() {
    MGraph g1;
	setupMatrixGraph(&g1);

	printf("have %d num!\n", g1.edgeNum);
    return 0;
}
