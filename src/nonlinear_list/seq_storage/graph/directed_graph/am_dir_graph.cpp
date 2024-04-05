/********************************************************************************
* @author: Shuobin
* @date: 2024/3/20 17:39
* @version: 1.0
* @description: 邻接矩阵实现有向图
********************************************************************************/
#include <stdio.h>
#include <stack>
#include <queue>
#include "am_dir_graph.h"

AmDirGraph getAmDirGraph() {
    AmDirGraph g;
    g.vexNum = 0;
    for (int i = 0; i <= MAX_NODES - 1; i++) {
        g.vexes[i] = '\0';
    }
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            g.matrix[i][j] = 0;
        }
    }
    return g;
}

int addVex(AmDirGraph &g, VEX_TYPE nodeVal) {
    if (isFull(g)) {
        return -1;
    }
    g.vexes[g.vexNum++] = nodeVal;
    return g.vexNum - 1;
}

bool addArc(AmDirGraph &g, VEX_TYPE vex1, VEX_TYPE vex2) {
    //找到vex1和vex2的数组下标
    int vex1Idx = findVex(g, vex1);
    int vex2Idx = findVex(g, vex2);
    if (vex1Idx == -1 || vex2Idx == -1) {
        VEX_TYPE tmp = vex1Idx == -1 ? vex1 : vex2;
        printf("Exception: %c Element not found\n", tmp);
        return false;
    }
    g.matrix[vex1Idx][vex2Idx] = 1;
    return true;
}

int findVex(AmDirGraph &g, VEX_TYPE vex) {
    for (int i = 0; i <= g.vexNum - 1; i++) {
        if (g.vexes[i] == vex) {
            return i;
        }
    }
    return -1;
}

bool isFull(AmDirGraph &g) {
    return g.vexNum >= MAX_NODES;
}

void bfs(AmDirGraph &g) {
    //找到起始顶点，然后相邻的顶点，再将其加入队列中
    bool visited[g.vexNum];
    for (int i = 0; i <= g.vexNum - 1; i++) {
        visited[i] = false;
    }
    for (int i = 0; i <= g.vexNum - 1; i++) {
        if (!visited[i]) {    //为了处理图可能有两个或以上连通分量
            //从i节点作为起点开始访问
            std::queue<int> queue;
            queue.push(i);
            visited[i] = true;
            printf("%c ", g.vexes[i]);
            while (queue.size() > 0) {
                int eleIdx = queue.front();
                queue.pop();
                //找到与targetIdx直接相连且未被访问的节点，放入队列
                for (int i = 0; i <= g.vexNum - 1; i++) {
                    if (g.matrix[eleIdx][i] == 1 && !visited[i]) {
                        queue.push(i);
                        visited[i] = true;
                        printf("%c ", g.vexes[i]);
                    }
                }
            }
            printf("\n");
        }
    }
}

void dfsByRecursionImpl(AmDirGraph &g, int i, bool *visited) {
    //visit 节点i
    //找到与i相邻且未被访问的节点，依次递归访问
    printf("%c ", g.vexes[i]);
    visited[i] = true;
    for (int j = 0; j <= g.vexNum - 1; j++) {
        if (g.matrix[i][j] == 1 && !visited[j]) {
            dfsByRecursionImpl(g, j, visited);
        }
    }
}

void dfsByRecursion(AmDirGraph &g) {
    bool visited[g.vexNum];
    for (int i = 0; i <= g.vexNum - 1; i++) {
        visited[i] = false;
    }
    for (int i = 0; i <= g.vexNum - 1; i++) {
        if (!visited[i]) { //处理非连通图
            dfsByRecursionImpl(g, i, visited);
            printf("  ");
        }
    }
}

void dfsByStackImpl(AmDirGraph &g, int i, bool *visited) {
    std::stack<int> stack;
    stack.push(i);
    visited[i] = true;
    while (stack.size() > 0) {
        int ele = stack.top();
        stack.pop();
        printf("%c", g.vexes[ele]);
        for (int j = g.vexNum - 1; j >= 0; j--) {
            if (g.matrix[ele][j] == 1 && !visited[j]) {
                stack.push(j);
                visited[j] = true;
            }
        }
    }
}

void dfsByStack(AmDirGraph &g) {
    bool visited[g.vexNum];
    for (int i = 0; i <= g.vexNum - 1; i++) {
        visited[i] = false;
    }
    for (int i = 0; i <= g.vexNum - 1; i++) {
        if (!visited[i]) { //处理非连通图
            dfsByStackImpl(g, i, visited);
            printf("  ");
        }
    }
}

void dfs(AmDirGraph &g, short opt) {
    if (opt == 1) {
        //递归实现
        dfsByRecursion(g);
    } else if (opt == 2) {
        //非递归实现
        dfsByStack(g);
    }
}
