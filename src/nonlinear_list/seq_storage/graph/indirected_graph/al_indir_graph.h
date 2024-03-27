/********************************************************************************
* @author: Shuobin
* @date: 2024/3/20 17:41
* @version: 1.0
* @description: 邻接表实现无向图
********************************************************************************/
#ifndef DATA_STRUCTURE_AL_INDIR_GRAPH_H
#define DATA_STRUCTURE_AL_INDIR_GRAPH_H
#define VEX_TYPE char       //图中结点的数据类型
#define INIT_VEX_SIZE 10    //图中可容纳的初始最大结点容量

/**
 * 邻接表的边节点
 */
typedef struct ArcNode {
    int i;  //边所指向的节点在vexList中的下标
    ArcNode *next;
} ArcNode;

/**
 * 邻接表的表头节点
 */
typedef struct VNode {
    VEX_TYPE data;     //节点中的数据
    ArcNode *firstArc; //指向的第一个边节点
} VNode, VNodeList[INIT_VEX_SIZE];

typedef struct ALGraph {
    VNodeList vexList;
    int vexNum, arcNum, maxCapacity; //记录图中已有的顶点数，边数和图可容纳的最大节点容量
} ALGraph;

/**
 * 创建无向图
 * @return 新创建的无向图
 */
ALGraph getALGraph();

/**
 * 向图中添加新的节点
 * @param g
 * @param vex 新节点
 * @return 新节点的数组下标。若返回值为-1，说明插入失败，返回值大于0，说明插入成功，
 */
int addVex(ALGraph &g, VEX_TYPE vex);

/**
 * 在两个节点之间添加边
 * @param g
 * @param vex1
 * @param vex2
 * @return
 */
bool addArc(ALGraph &g, VEX_TYPE vex1, VEX_TYPE vex2);

/**
 * 为vexListIdx对应的表头节点添加新的边节点
 * @param g
 * @param vexIdx 邻接表中的表头结点对应的下标
 * @param arc 边节点
 * @return
 */
bool addArcNodeToVex(ALGraph &g, int vexIdx, ArcNode &arc);

void dfs(ALGraph &g);

void bfs(ALGraph &g);

/**
 * 图中是否能继续添加新的节点
 * @param g 目标图
 * @return true代表满
 */
bool isFull(ALGraph &g);

/**
 * 判断目标元素是否在图中
 * @param g
 * @param e 目标元素的值
 * @return -1代表目标元素不在图中，返回值大于0则代表元素的数组下标
 */
int isExist(ALGraph &g, VEX_TYPE e);

#endif //DATA_STRUCTURE_AL_INDIR_GRAPH_H
