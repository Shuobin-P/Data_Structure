/********************************************************************************
* @author: Shuobin
* @date: 2024/3/20 17:39
* @version: 1.0
* @description: 邻接列表实现有向图
********************************************************************************/
#include <stdio.h>
#include <cstddef>
#include <malloc.h>
#include <queue>
#include <stack>
#include "al_dir_graph.h"

using namespace std;

ALDirGraph getALDirGraph() {
    ALDirGraph g;
    g.vexNum = 0;
    g.arcNum = 0;
    g.maxCapacity = INIT_VEX_SIZE;
    return g;
}

int addVex(ALDirGraph &g, VEX_TYPE vex) {
    if (isFull(g)) return -1;
    int tmp = isExist(g, vex);
    if (tmp >= 0) return tmp;
    g.vexList[g.vexNum] = {vex, NULL};
    return g.vexNum++;
}

bool addArc(ALDirGraph &g, VEX_TYPE vex1, VEX_TYPE vex2) {
    int vex1Idx = isExist(g, vex1);
    int vex2Idx = isExist(g, vex2);
    if (vex1Idx == -1 || vex2Idx == -1) { //保证两个结点已经存在
        printf("Exception: %c doesn't exist", vex1Idx == -1 ? vex1 : vex2);
        return false;
    }
    addArcNodeToVex(g, vex1Idx, vex2Idx);
    return true;
}

bool addArcNodeToVex(ALDirGraph &g, int vexIdx, int arcIdx) {
    if (vexIdx + 1 > g.vexNum || vexIdx + 1 > g.maxCapacity) { //防止表头结点不存在
        return false;
    }
    ArcNode *ptr = g.vexList[vexIdx].firstArc;
    ArcNode *t = (ArcNode *) malloc(sizeof(ArcNode));
    t->i = arcIdx;
    t->nextArc = NULL;
    if (ptr == NULL) {
        g.vexList[vexIdx].firstArc = t;
        g.arcNum++;
        return true;
    } else {
        while (ptr->nextArc != NULL) {
            ptr = ptr->nextArc;
        }
        ptr->nextArc = t;
        g.arcNum++;
        return true;
    }
}

void bfs(ALDirGraph &g) {
    queue<int> queue;
    bool visited[g.vexNum];
    for (int i = 0; i <= g.vexNum - 1; i++) {
        visited[i] = false;
    }
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
                    ptr = ptr->nextArc;
                }
            }
        }
    }
}

void dfsImplByIncur(ALDirGraph &g, int idx, bool *visited) {
    ArcNode *ptr = g.vexList[idx].firstArc;
    visited[idx] = true;
    printf("%c ", g.vexList[idx].data);
    while (ptr != NULL) {
        //ptr->i
        if (!visited[ptr->i]) {
            dfsImplByIncur(g, ptr->i, visited);
        }
        ptr = ptr->nextArc;
    }
}

void dfsByStack(ALDirGraph &g, int idx, bool *visited) {
    stack<int> stack, t;
    stack.push(idx);
    visited[idx] = true;
    while (stack.size() > 0) {
        int top = stack.top();
        stack.pop();
        printf("%c ", g.vexList[top].data);
        ArcNode *ptr = g.vexList[top].firstArc;
        while (ptr != NULL) {
            if (!visited[ptr->i]) {
                t.push(ptr->i);
                visited[ptr->i] = true;
            }
            ptr = ptr->nextArc;
        }
        while (t.size() > 0) {
            stack.push(t.top());
            t.pop();
        }
    }
}

void dfs(ALDirGraph &g, int opt) {
    bool visited[g.vexNum];
    for (int i = 0; i <= g.vexNum - 1; i++) {
        visited[i] = false;
    }
    for (int i = 0; i <= g.vexNum - 1; i++) {
        if (!visited[i]) {
            if (opt == 1) {
                dfsImplByIncur(g, i, visited);
            } else if (opt == 2) {
                dfsByStack(g, i, visited);
            }
        }
    }
}

bool isFull(ALDirGraph &g) {
    if (g.vexNum >= g.maxCapacity) return true;
    return false;
}

int isExist(ALDirGraph &g, VEX_TYPE e) {
    for (int i = 0; i <= g.vexNum - 1; i++) {
        if (g.vexList[i].data == e) {
            return i;
        }
    }
    return -1;
}

bool existArc(ALDirGraph &g, bool *visited, int root, int target) {
    //结束条件：
    //if(root == target) return true;
    //ptr = g.vexList[root].nextArc
    /*
     * while(!(isExist or ptr == NULL )) {
     *  tmp = existArc(g, visited, ptr->i, target, isExist)
     *  if(tmp) {
     *      return true
     *  }
     *  ptr = ptr -> nextArc
     * }
     * return false
    */
    if (root == target) return true;
    visited[root] = true;
    ArcNode *ptr = g.vexList[root].firstArc;
    while (!(ptr == NULL)) {
        if (!visited[ptr->i]) {
            bool tmp = existArc(g, visited, ptr->i, target);
            if (tmp) return true;
        }
        ptr = ptr->nextArc;
    }
    return false;
}

bool existArcDFS(ALDirGraph &g, int i, int j) {
    //基于深度优先遍历实现，是否存在vi到vj的路径
    //从vi出发进行深度有先遍历
    bool visited[g.vexNum];
    for (int i = 0; i <= g.vexNum - 1; i++) {
        visited[i] = false;
    }
    return existArc(g, visited, i, j);
}

bool existArcBFS(ALDirGraph &g, int i, int j) {
    queue<int> queue;
    bool visited[g.vexNum];
    for (int idx = 0; idx < g.vexNum; idx++) {
        visited[idx] = false;
    }
    queue.push(i);
    visited[i] = true;
    while (queue.size() > 0) {
        int head = queue.front();
        queue.pop();
        if (head == j) {
            return true;
        }
        ArcNode *p = g.vexList[head].firstArc;
        while (p != NULL) {
            int neighbor = p->i;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                if (neighbor == j) return true;
                queue.push(neighbor);
            }
            p = p->nextArc;
        }
    }
    return false;
}

bool arcIsExist(ALDirGraph &g, int i, int j, short opType) {
    if (opType == 0) return existArcDFS(g, i, j);
    else if (opType == 1) return existArcBFS(g, i, j);
}


