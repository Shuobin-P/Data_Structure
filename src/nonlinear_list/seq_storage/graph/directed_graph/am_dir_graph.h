/********************************************************************************
* @author: Shuobin
* @date: 2024/3/20 17:39
* @version: 1.0
* @description: 邻接矩阵实现有向图
********************************************************************************/

#ifndef DATA_STRUCTURE_AM_DIR_GRAPH_H
#define DATA_STRUCTURE_AM_DIR_GRAPH_H
#define VEX_TYPE char
#define MAX_ROWS 20
#define MAX_COLS 20
#define MAX_NODES 20
typedef struct {
    short matrix[MAX_ROWS][MAX_COLS];   //存储边
    VEX_TYPE vexes[MAX_NODES];          //存储图中的顶点
    int vexNum;                         //图中当前顶点数
} AmDirGraph;

AmDirGraph getAmDirGraph();

int addVex(AmDirGraph &g, VEX_TYPE nodeVal);

bool addArc(AmDirGraph &g, VEX_TYPE vex1, VEX_TYPE vex2);

void bfs(AmDirGraph &g);

void dfs(AmDirGraph &g, short opt);


#endif //DATA_STRUCTURE_AM_DIR_GRAPH_H
