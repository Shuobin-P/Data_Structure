/********************************************************************************
* @author: Shuobin
* @date: 2024/3/20 17:41
* @version: 1.0
* @description: 邻接表实现无向图
********************************************************************************/
#include <stdio.h>
#include <malloc.h>
#include <cstddef>
#include <queue>
#include <stack>

#include "al_indir_graph.h"

using namespace std;

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
        printf("Exception: %c doesn't exist\n", vex1Idx == -1 ? vex1 : vex2);
        return false;
    }
    addArcNodeToVex(g, vex1Idx, vex2Idx);
    addArcNodeToVex(g, vex2Idx, vex1Idx);
    return true;
}

bool addArcNodeToVex(ALGraph &g, int vexIdx, int arcIdx) {
    if (vexIdx + 1 > g.vexNum || vexIdx + 1 > g.maxCapacity) { //防止表头结点不存在
        return false;
    }
    ArcNode *ptr = g.vexList[vexIdx].firstArc;
    ArcNode *t = (ArcNode *) malloc(sizeof(ArcNode));
    t->i = arcIdx;
    t->next = NULL;
    if (ptr == NULL) {
        g.vexList[vexIdx].firstArc = t;
        g.arcNum++;
        return true;
    } else {
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = t;
        g.arcNum++;
        return true;
    }
}

void dfsImpl(ALGraph &g, int vexIdx, bool *visited) {
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

void dfsByRecur(ALGraph &g) {
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

void dfsByStack(ALGraph &g) {
    stack<int> stack, t;
    bool visited[g.vexNum];
    for (int i = 0; i <= g.vexNum - 1; i++) {
        visited[i] = false;
    }
    for (int i = 0; i <= g.vexNum - 1; i++) {
        if (!visited[i]) {
            stack.push(i);
            visited[i] = true;
            while (stack.size() > 0) {
                int top = stack.top();
                stack.pop();
                printf("%c ", g.vexList[top].data);
                //把top相邻且未被访问的结点，从右往左依次加入栈
                ArcNode *ptr = g.vexList[top].firstArc;
                while (ptr != NULL) {   //死循环
                    if (!visited[ptr->i]) {
                        t.push(ptr->i);
                        visited[ptr->i] = true;
                        ptr = ptr->next;
                    } else {
                        ptr = ptr->next;
                    }
                }
                while (t.size() > 0) {
                    stack.push(t.top());
                    t.pop();
                }
            }
        }
    }
}

void dfs(ALGraph &g, short opt) {
    if (opt == 1) {
        dfsByRecur(g);
    } else if (opt == 2) {
        dfsByStack(g);
    }
}

void bfs(ALGraph &g) {
    bool visited[g.vexNum];
    for (int i = 0; i <= g.vexNum - 1; i++) {
        visited[i] = false;
    }
    queue<int> queue;
    for (int i = 0; i <= g.vexNum - 1; i++) {
        if (!visited[i]) {
            queue.push(i);
            visited[i] = true;
            while (queue.size() > 0) {
                int head = queue.front();
                queue.pop();
                printf("%c ", g.vexList[head].data);
                ArcNode *ptr = g.vexList[head].firstArc;
                while (ptr != NULL) {
                    if (!visited[ptr->i]) {
                        queue.push(ptr->i);
                        visited[ptr->i] = true;
                    }
                    ptr = ptr->next;
                }
            }
        }
    }
    printf("\n");
}

void bfsMinDistance(ALGraph &g, int idx) {
    queue<int> queue;
    bool visited[g.vexNum];
    int distance[g.vexNum]; //存储从下标为idx的元素到其它节点的最短路径
    for (int i = 0; i <= g.vexNum - 1; i++) {
        visited[i] = false;
        distance[i] = -1;
    }
    distance[idx] = 0;
    queue.push(idx);
    visited[idx] = true;
    while (queue.size() > 0) {
        int head = queue.front();
        queue.pop();
        ArcNode *ptr = g.vexList[head].firstArc;
        while (ptr != NULL) {
            if (!visited[ptr->i]) {
                queue.push(ptr->i);
                visited[ptr->i] = true;
                distance[ptr->i] = distance[head] + 1;
            }
            ptr = ptr->next;
        }
    }
    for (int i = 0; i <= g.vexNum - 1; i++) {
        printf("%c to %c's shortest distance=%d\n", g.vexList[idx].data, g.vexList[i].data, distance[i]);
    }
    printf("\n");
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
