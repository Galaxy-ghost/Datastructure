//
// Created by Galaxy. on 2023/5/15.
//

#ifndef DATASTRUCTURE_TOPOLOGICALSORT_H
#define DATASTRUCTURE_TOPOLOGICALSORT_H
// NOTE 
/* 拓扑排序，AOV网，顶点表示活动，通过有向图，表示活动之间的先后关系
 * 		拓扑排序可以判断有向图是否有环的算法（找出来拓扑排序的节点数少于图中顶点数）
 * 拓扑排序的算法过程：
 * 1. 从有向图中选择一个没有前驱（入度为0）的顶点，输出
 * 2. 删除第1步中的顶点，并删除从该顶点出发的所有的出度边，再找当前图中入度为0的顶点
 * 3. 重复上述2个步骤
 * */
// 使用邻接表来描述AOV网
#include "../02.AdjacentList/adjacentList.h"
// 返回值为1表示含有环，0表示无环，-1表示出现错误
int TopologicalSort(AGraph *graph);

#endif //DATASTRUCTURE_TOPOLOGICALSORT_H
