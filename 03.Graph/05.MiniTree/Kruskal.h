//
// Created by Galaxy. on 2023/5/12.
//

#ifndef DATASTRUCTURE_KRUSKAL_H
#define DATASTRUCTURE_KRUSKAL_H
// Kruskal算法
// 利用边集数组和并查集构建最小生成树
#include "../01.MatrixGraph/matrixGraph.h"
#include "../base.h"

// 利用邻接矩阵初始化边集数组
int initEdgeSet(const MGraph *graph, EdgeSet *edges);
// 对边集数组按照权值从小到大排序
void sortEdgeSet(EdgeSet *edges, int num);
// 按照kruskal算法构建最小生成树
int KruskalMGraph(const MGraph *graph, const EdgeSet *edges, int num, EdgeSet *result);

#endif //DATASTRUCTURE_KRUSKAL_H
