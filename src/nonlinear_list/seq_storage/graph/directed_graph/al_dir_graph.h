/********************************************************************************
* @author: Shuobin
* @date: 2024/3/20 17:39
* @version: 1.0
* @description: 邻接列表实现有向图
********************************************************************************/
#ifndef DATA_STRUCTURE_AL_DIR_GRAPH_H
#define DATA_STRUCTURE_AL_DIR_GRAPH_H
#define VEX_TYPE char       //图中结点的数据类型
#define INIT_VEX_SIZE 15    //图中可容纳的初始最大结点容量

/**
 * 邻接表的边节点
 */
typedef struct ArcNode {
    int i;  //边所指向的节点在vexList中的下标
    struct ArcNode *next;
} ArcNode;

/**
 * 邻接表的表头节点
 */
typedef struct VNode {
    VEX_TYPE data;     //节点中的数据
    ArcNode *firstArc;
} VNodeList[INIT_VEX_SIZE];

/**
 * 有向图
 */
typedef struct ALDirGraph {
    VNodeList vexList;
    int vexNum, arcNum, maxCapacity; //记录图中已有的顶点数，边数和图可容纳的最大节点容量
} ALDirGraph;

/**
 * 使用邻接链表创建有向图
 * @return 新的有向图
 */
ALDirGraph getALDirGraph();

int addVex(ALDirGraph &g, VEX_TYPE vex);

bool addArc(ALDirGraph &g, VEX_TYPE x, VEX_TYPE y);

/**
 * 深度优先遍历
 * @param g
 */
void dfs(ALDirGraph &g, int opt);

/**
 * 广度优先遍历
 * @param g
 */
void bfs(ALDirGraph &g);

bool isFull(ALDirGraph &g);

/**
 * 判断有向图中是否存在节点e
 * @param g
 * @param e
 * @return 返回值若为-1代表不存在；正数即为元素在vexList的下标位置
 */
int isExist(ALDirGraph &g, VEX_TYPE e);

bool addArcNodeToVex(ALDirGraph &g, int vexIdx, int arcIdx);

/**
 * 基于深度优先遍历，判断vi顶点和vj顶点之间是否存在路径
 * @param g
 * @param i vi
 * @param j vj
 * @return
 */
bool arcIsExist(ALDirGraph &g, int i, int j);

#endif //DATA_STRUCTURE_AL_DIR_GRAPH_H
