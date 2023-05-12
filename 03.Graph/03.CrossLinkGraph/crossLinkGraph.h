//
// Created by Galaxy. on 2023/5/11.
//

#ifndef DATASTRUCTURE_CROSSLINKGRAPH_H
#define DATASTRUCTURE_CROSSLINKGRAPH_H

// 十字链表的图表示法，将邻接表和逆邻接表整合在一个顶点描述的结构上
// 方便计算出度和入度

// 十字链表的边的结构
typedef struct arcBox
{
    int tailVertex;          //  弧尾编号（从该点指向其他点），入度的信息
    struct arcBox* tailNext; // 用于存储下一个以首元节点为弧尾巴顶点的节点
    int headVertex;          // 以首元节点为弧头的节点位于数组的位置下标
    struct arcBox* headNext; // 用于存储下一个以首元节点为弧头顶点的节点
    int weight;              // 权重
} ArcBox;

// 顶点结构
typedef struct
{
    int no;           // 节点编号
    char* show;       // 节点展示信息
    ArcBox* firstOut; // 节点的出度
    ArcBox* firstIn;  // 节点的入度
} CrossVertex;

// 十字链表的图结构
typedef struct
{
    CrossVertex* nodes; // 图的顶点指针
    int numVertex;      // 图中顶点的数量
    int numEdge;        // 图中边的数量
} CrossGraph;

// 产生n个节点的十字链表
CrossGraph* createCrossGraph(int n);
// 释放十字链表
void releaseCrossGraph(CrossGraph* graph);
// 初始化十字链表
void initCrossGraph(CrossGraph* graph, char* names[], int num);
// 添加一条从tail到head的边
void addCrossArc(CrossGraph* graph, int tail, int head, int w);
// 计算no编号节点的出度
int outDegreeCrossGraph(CrossGraph *graph, int no);
// 计算no编号节点的入度
int inDegreeCrossGraph(CrossGraph *graph, int no);

#endif // DATASTRUCTURE_CROSSLINKGRAPH_H
