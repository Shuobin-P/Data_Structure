/********************************************************************************
* @author: Shuobin
* @date: 2024/3/20 17:39
* @version: 1.0
* @description: 邻接矩阵实现有向图
********************************************************************************/

#ifndef DATA_STRUCTURE_AM_DIR_GRAPH_H
#define DATA_STRUCTURE_AM_DIR_GRAPH_H
#define VEX_TYPE char   //默认节点的数据类型为char
#define MAX_ROWS 20
#define MAX_COLS 20
#define MAX_NODES 20    //设置的最大节点数
typedef struct {
    short matrix[MAX_ROWS][MAX_COLS];   //存储边
    VEX_TYPE vexes[MAX_NODES];          //存储图中的顶点
    int vexNum;                         //图中当前顶点数
} AmDirGraph;

AmDirGraph getAmDirGraph();

int addVex(AmDirGraph &g, VEX_TYPE nodeVal);

/**
 * 在vex1和vex2之间添加边
 * @param g
 * @param vex1 弧的起点
 * @param vex2 弧的终点
 * @return true or false
 */
bool addArc(AmDirGraph &g, VEX_TYPE vex1, VEX_TYPE vex2);

void bfs(AmDirGraph &g);

void dfs(AmDirGraph &g, short opt);

bool isFull(AmDirGraph &g);

/**
 * 查找vex在g.vexes中的数组下标
 * @param g
 * @param vex 目标元素
 * @return 若返回值为-1，说明没找到；若返回值大于等于0，即为元素的数组下标
 */
int findVex(AmDirGraph &g, VEX_TYPE vex);

#endif //DATA_STRUCTURE_AM_DIR_GRAPH_H
