#ifndef DATASTRUCTURE_GRAPHBASE_H
#define DATASTRUCTURE_GRAPHBASE_H
#define MaxNodeNum 10
#define INF 0x3f3f3f3f
// 图的边集数组
typedef struct {
    int begin; // 边的开始
    int end; // 边的结束
    int weight; // 边的权值
}EdgeSet;

#endif //DATASTRUCTURE_GRAPHBASE_H

