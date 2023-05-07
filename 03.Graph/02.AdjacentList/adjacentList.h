//
// Created by Galaxy. on 2023/5/7.
//

#ifndef DATASTRUCTURE_ADJACENTLIST_H
#define DATASTRUCTURE_ADJACENTLIST_H

#include "../base.h"
// 边的结构
typedef struct arcEdge{
    int no; // 从首节到的节点编号
    int weight; // 边的权重
    struct arcEdge *next; // 指向下一条边
}ArcEdge;
// 顶点结构
typedef struct {
    int no; // 顶点编号
    char *show; // 顶点展示的内容
    ArcEdge *first; // 顶点的第一条边
}ArcNode;
// 图的结构
typedef struct {
    ArcNode *nodes; // 顶点的集合
    int edgeNum; // 边的个数
    int nodeNum; // 顶点的个数
    int directed; // 图的类型
}AGraph;

AGraph *createAGraph(int n); // 初始化邻接表
void releaseAGraph(AGraph *g); // 释放邻接表
void initAGraph(AGraph *g, int num, char *names[], int directed); // 初始化邻接表
void addAGraphEdge(AGraph *g, int x, int y, int w); // 给邻接表添加边

#endif //DATASTRUCTURE_ADJACENTLIST_H
