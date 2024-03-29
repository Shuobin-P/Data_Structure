/********************************************************************************
* @author: Shuobin
* @date: 2024/3/20 17:41
* @version: 1.0
* @description: 邻接表实现无向图
********************************************************************************/
#include <stdio.h>
#include <cstddef>
#include "al_indir_graph.h"

ALGraph getALGraph() {
    ALGraph g = {{}, 0, 0, INIT_VEX_SIZE};
    return g;
}

int addVex(ALGraph &g, VEX_TYPE vex) {
    if (isFull(g)) return -1;
    int tmp = isExist(g, vex);
    if (tmp >= 0) return tmp;
    g.vexList[g.vexNum] = {vex, NULL};
    return g.vexNum++;
}

bool addArc(ALGraph &g, VEX_TYPE vex1, VEX_TYPE vex2) {
    int vex1Idx = isExist(g, vex1);
    int vex2Idx = isExist(g, vex2);

    if (vex1Idx == -1 || vex2Idx == -1) { //保证两个结点已经存在
        printf("Exception: %c doesn't exist", vex1Idx == -1 ? vex1 : vex2);
        return false;
    }
    ArcNode arcVex2 = {vex2Idx, NULL};
    ArcNode arcVex1 = {vex1Idx, NULL};
    addArcNodeToVex(g, vex1Idx, arcVex2);
    addArcNodeToVex(g, vex2Idx, arcVex1);
    return true;
}

void dfsImpl(ALGraph &g, int vexIdx, bool* visited) {
    visited[vexIdx] = true;
    printf("%c ", g.vexList[vexIdx].data);
    ArcNode *ptr = g.vexList[vexIdx].firstArc;
    while (ptr) {
        if (!visited[ptr->i]) {
            dfsImpl(g, ptr->i, visited);
        }
        ptr = ptr->next;
    }

}

void dfs(ALGraph &g) {
    //创建一个visited数组记录深度遍历过程中结点的访问情况
    bool visited[g.vexNum];
    for (int i = 0; i <= g.vexNum - 1; i++) {
        visited[i] = false;
    }
    for (int i = 0; i <= g.vexNum - 1; i++) {
        if (!visited[i]) {
            dfsImpl(g, i, visited);
            printf("\t");
        }
    }

}

bool addArcNodeToVex(ALGraph &g, int vexIdx, ArcNode &arc) {
    if (vexIdx + 1 > g.vexNum || vexIdx + 1 > g.maxCapacity) { //防止表头结点不存在
        return false;
    }
    ArcNode *ptr = g.vexList[vexIdx].firstArc;
    if (ptr == NULL) {
//        printf("Add=%p", arc.next);
        g.vexList[vexIdx].firstArc = &arc;
        g.arcNum++;
        return true;
    }
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = &arc;
    //printf("ArcNode idx=%d, letter= %c\n", arc.i, g.vexList[arc.i].data);
    g.arcNum++;
    return true;
}

bool isFull(ALGraph &g) {
    if (g.vexNum >= g.maxCapacity) return true;
    return false;
}

int isExist(ALGraph &g, VEX_TYPE e) {
    for (int i = 0; i <= g.vexNum - 1; i++) {
        if (g.vexList[i].data == e) {
            return i;
        }
    }
    return -1;
}
