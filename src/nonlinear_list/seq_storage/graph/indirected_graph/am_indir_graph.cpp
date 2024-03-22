/********************************************************************************
* @author: Shuobin
* @date: 2024/3/20 17:41
* @version: 1.0
* @description: 邻接矩阵实现无向图
********************************************************************************/
#include <stdio.h>
#include <queue>
#include "am_indir_graph.h"

AMIndGraph createGraph() {
    AMIndGraph newGraph = {0, 0, 0};
    return newGraph;
}

int insertNode(AMIndGraph &g, VEX_TYPE nodeVal) {
    if (isFull(g)) return -1;
    g.vexes[g.vexNum++] = nodeVal;
    return g.vexNum - 1;
}

bool insertEdge(AMIndGraph &g, VEX_TYPE xNode, VEX_TYPE yNode) {
    int xIndex = findVex(g, xNode);
    int yIndex = findVex(g, yNode);
    if (xIndex < 0 || yIndex < 0) {
        VEX_TYPE tmp = xIndex < 0 ? xNode: yNode;
        printf("Exception: %c Element not found\n", tmp);
        return false;
    }
    //判断图中，两个节点之间是否已经有边
    if (g.matrix[xIndex][yIndex] == 1) return true;
    //若没有边，则插入边
    g.matrix[xIndex][yIndex] = 1;
    g.matrix[yIndex][xIndex] = 1;
    return true;
}

void bfsNode(AMIndGraph &g, int targetIdx, bool* visited) {
    //找到与targetIdx直接相连且未被访问的节点，放入队列
    std::queue <int> queue;
    queue.push(targetIdx);
    visited[targetIdx] = true;
    printf("%c ", g.vexes[targetIdx]);
    while(queue.size() > 0) {
        int eleIdx = queue.front();
        queue.pop();
        //找到与targetIdx直接相连且未被访问的节点，放入队列
        for(int i = 0; i <= g.vexNum - 1; i++) {
            if(g.matrix[eleIdx][i] == 1 && !visited[i]) {
                queue.push(i);
                visited[i] = true;
                printf("%c ", g.vexes[i]);
            }
        }
    }
    printf("\n");
}

void bfs(AMIndGraph &g) {
    //注意：图可能有两个或以上连通分量
    bool visited[g.vexNum] = {false};
    for(int i = 0; i <= g.vexNum - 1; i++) {
        if(!visited[i]) {
            //从i节点作为起点开始访问
            bfsNode(g, i, visited);
        }
    }
}

bool isFull(AMIndGraph &g) {
    return g.vexNum >= MAX_NODES;
}

int findVex(AMIndGraph &g, VEX_TYPE target) {
    for (int i = 0; i <= MAX_NODES - 1; i++) {
        if (g.vexes[i] == target) return i;
    }
    return -1;
}

