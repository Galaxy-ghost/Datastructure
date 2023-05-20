//
// Created by Galaxy. on 2023/5/19.
//

#include "keyPath.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int TopologicalSort(AGraph* graph, int* ETV, int* LTV)
{
    int* inDegree = (int*) malloc(sizeof(int) * graph->nodeNum);
    if (inDegree == NULL) {
        fprintf(stderr, "malloc error!\n");
        return -1;
    }
    memset(inDegree, 0, sizeof(int) * graph->nodeNum);
    // 首先对inDegree根据出图对inDegree进行初始化
    for (int i = 0; i < graph->nodeNum; i++) {
        if (graph->nodes[i].first) {
            ArcEdge* edge = graph->nodes[i].first;
            while (edge) {
                inDegree[edge->no]++;
                edge = edge->next;
            }
        }
    }
    // 对入度为0的节点进行入栈
    // 这里要申请两个栈，一个用于更新ETV，一个用来更新LTV
    int* stack = (int*) malloc(sizeof(int) * graph->nodeNum);
    int* topOut = (int*) malloc(sizeof(int) * graph->nodeNum);
    int top = -1;
    int index = 0;
    if (stack == NULL || topOut == NULL) {
        free(inDegree);
        fprintf(stderr, "malloc error!\n");
        return -1;
    }
    for (int i = 0; i < graph->nodeNum; i++) {
        if (inDegree[i] == 0) {
            stack[++top] = i;
            break; // 因为是求关键路径所以只有一个源点
        }
    }
    int tmp;
    while (top != -1) {
        tmp = stack[top--];
        topOut[index++] = tmp;
        if (graph->nodes[tmp].first) {
            ArcEdge* edge = graph->nodes[tmp].first;
            while (edge) {
                inDegree[edge->no]--;
                if (inDegree[edge->no] == 0) {
                    stack[++top] = edge->no;
                }
                // 更新ETV
                if (ETV[tmp] + edge->weight > ETV[edge->no]) {
                    ETV[edge->no] = ETV[tmp] + edge->weight;
                }
                edge = edge->next;
            }
        }
    }
    free(inDegree);
    free(stack);
    if (index < graph->nodeNum) { // 说明出现了环
        free(topOut);
        return -1;
    }
    // 对LTV进行初始化
    for (int i = 0; i < graph->nodeNum; i++) {
        LTV[i] = ETV[tmp];
    }
    int getTopNo;
    // 根据topOut的顺序对LTV进行更新
    while (index) {
        getTopNo = topOut[--index];
        ArcEdge* edge = graph->nodes[getTopNo].first;
        while (edge) {
            if (LTV[getTopNo] > LTV[edge->no] - edge->weight) {
                LTV[getTopNo] = LTV[edge->no] - edge->weight;
            }
            edge = edge->next;
        }
    }
    free(topOut);
    return 0;
}

static void showTable(int* table, int n, const char* name)
{
    printf("%s", name);
    for (int i = 0; i < n; i++) {
        printf("\t%d", table[i]);
    }
    printf("\n");
}

/*为了统计关键路径需要记录AOE网中的四个数据
 * 对于顶点来说有两个数据
 * ETV：到达该事件的最早时间
 * LTV：到达该事件的最晚时间
 * 对于活动来说有两个数据
 * ETE：执行该活动的最早时间
 * LTE：执行该活动的最晚时间
 */
void keyPath(AGraph* graph)
{
    int* ETV = (int*) malloc(sizeof(int) * graph->nodeNum);
    int* LTV = (int*) malloc(sizeof(int) * graph->nodeNum);
    if (ETV == NULL || LTV == NULL) {
        fprintf(stderr, "malloc error!\n");
        return;
    }
    memset(ETV, 0, sizeof(int) * graph->nodeNum);
    memset(LTV, 0, sizeof(int) * graph->nodeNum);
    // 填充ETV和LTV
    TopologicalSort(graph, ETV, LTV);
    showTable(ETV, graph->nodeNum, "ETV: ");
    showTable(LTV, graph->nodeNum, "LTV: ");
    // 计算ETE和LTE
    for (int i = 0; i < graph->nodeNum; i++) {
        ArcEdge* edge = graph->nodes[i].first;
        while (edge) {
            if (ETV[i] == LTV[edge->no] - edge->weight) {
                printf(
                    "<%s> ---%d--- <%s>\n",
                    graph->nodes[i].show,
                    edge->weight,
                    graph->nodes[edge->no].show);
            }
            edge = edge->next;
        }
    }
    free(ETV);
    free(LTV);
}
