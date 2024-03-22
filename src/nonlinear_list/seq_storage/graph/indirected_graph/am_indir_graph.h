/********************************************************************************
* @author: Shuobin
* @date: 2024/3/20 17:41
* @version: 1.0
* @description: 邻接矩阵实现无向图
********************************************************************************/

#ifndef DATA_STRUCTURE_AM_INDIR_GRAPH_H
#define DATA_STRUCTURE_AM_INDIR_GRAPH_H
#define VEX_TYPE char
#define MAX_ROWS 20
#define MAX_COLS 20
#define MAX_NODES 20
typedef struct {
    short matrix[MAX_ROWS][MAX_COLS]; //存储边
    VEX_TYPE vexes[MAX_NODES];   //存储图中的顶点
    int vexNum;                  //图中当前顶点数
}AMIndGraph;

/**
 * 创建一个新图
 */
AMIndGraph createGraph();
/**
 * 向图中增加新的节点
 * @param g 目标图
 * @param nodeVal 插入的节点值
 * @return 若返回-1，说明插入失败；否则，返回顶点的数组下标
 */
int insertNode(AMIndGraph &g, VEX_TYPE nodeVal);

/**
 * 在指定的两个节点之间插入边
 * @param g
 * @param xNode
 * @param yNode
 * @return true代表成功，false代表失败
 */
bool insertEdge(AMIndGraph &g, VEX_TYPE xNode, VEX_TYPE yNode);

/**
 * 广度优先遍历图
 * @param g
 */
void bfs(AMIndGraph &g);

/**
 * 深度优先遍历
 * @param g
 * @param opt 1：递归实现 2：非递归实现
 */
void dfs(AMIndGraph &g, short opt);

/**
 * 判断图是否还能插入新节点
 * @param g
 * @return
 */
bool isFull(AMIndGraph &g);

/**
 * 查找目标节点是否在数组中，如果在，返回其数组下标；否则，返回-1
 * @param g
 * @param target
 * @return
 */
int findVex(AMIndGraph &g, VEX_TYPE target);
#endif //DATA_STRUCTURE_AM_INDIR_GRAPH_H
