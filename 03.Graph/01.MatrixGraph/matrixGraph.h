//
// Created by Galaxy. on 2023/4/27.
//

#ifndef DATASTRUCTURE_MATRIXGRAPH_H
#define DATASTRUCTURE_MATRIXGRAPH_H

/* 图的邻接矩阵存储方式
*  描述顶点和边集合
*  顶点用一维数组存储，边用二维数组存储
*/
#include "../base.h"
// 顶点结构
typedef struct {
    int no; // 顶点编号
    char *show; // 图中顶点显示的数据
}MatrixVertex;
// 邻接矩阵边的类型，用int来表示，即可以描述权值和是否有边
typedef int MatrixEdge;
// 邻接矩阵表示的图
typedef struct {
    MatrixVertex vex[MaxNodeNum]; // 邻接矩阵边的点的集合
    int nodeNum; // 邻接矩阵的点的个数
    MatrixEdge edge[MaxNodeNum][MaxNodeNum]; // 邻接矩阵的边
    int edgeNum; // 边的个数
    int directed; // 图的类型
}MGraph;

/* 邻接矩阵图的初始化，初始化顶点集合
*  num      ：顶点个数
*  names    ：顶点显示的字符串
*  directed ：图的类型，1表示有向图，0表示无向图
*  edgeValue：初始化边的权值
*/
void initGraph(MGraph *g, int num, char *names[], int directed, int edgeValue);
/* 添加边的信息
*  x        ：起始顶点编号
*  y        ：终止顶点编号
*  w        ：该边的权值
*/
void addMGraphEdge(MGraph *g, int x, int y, int w);
// 访问节点
void visitMGraphNode(MatrixVertex *node);
// 清空已访问记录表
void clearMGraphVisit();
// 深度遍历，从v号顶点开始遍历
void DFSMGraphTravel(MGraph *graph, int v);
// 广度遍历
void BFSMGraphTravel(MGraph *graph, int v);

#endif //DATASTRUCTURE_MATRIXGRAPH_H
