//
// Created by Galaxy. on 2023/5/19.
//

#ifndef DATASTRUCTURE_KEYPATH_H
#define DATASTRUCTURE_KEYPATH_H
/*关键路径是AOE网，顶点表示事件，边表示活动
* 关键路径就是在将AOE网看成整个项目，求出项目完成的最少时间
* 即找出AOE网中从源点到汇点的最长的路径
*/
#include "../02.AdjacentList/adjacentList.h"

void keyPath(AGraph* graph);

#endif //DATASTRUCTURE_KEYPATH_H
