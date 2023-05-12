//
// Created by Galaxy. on 2023/5/11.
//

#ifndef DATASTRUCTURE_ADJACENCYMULTILIST_H
#define DATASTRUCTURE_ADJACENCYMULTILIST_H

// 邻接多重表，适用于无向图，边的删除操作比较频繁的图
// 无向图如果要用邻接表存储，进行删除的话，操作比较复杂，一条边要处理两次

// 邻接多重表的边结构
typedef struct amlEdge
{
    int iVex;              // 顶点的编号
    struct amlEdge* iNext; // 分别指向与ivex、jvex相关的下一个边
    int jVex;
    struct amlEdge* jNext;
    int weight;
} MultiListEdge;

typedef struct
{
    int no;                   // 顶点编号
    char* name;               // 顶点展示的内容
    MultiListEdge* firstEdge; // 与该顶点相关的一条边
} MultiListVertex;

typedef struct
{
    MultiListVertex* nodes;
    int numVertex; // 顶点数量
    int numEdge;   // 边的数量
} AdjacencyMultiList;

// 创建n个节点的邻接表
AdjacencyMultiList* createMultiList(int n);
// 释放领接表
void releaseMultiList(AdjacencyMultiList* graph);
// 初始化邻接表
void initMultiList(AdjacencyMultiList* graph, char* names[], int num);
// 插入边
void insertMultiListEdge(AdjacencyMultiList* graph, int a, int b, int w);
// 删除边
int deleteMultiListEdge(AdjacencyMultiList* graph, int a, int b);


#endif // DATASTRUCTURE_ADJACENCYMULTILIST_H
