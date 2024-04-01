/********************************************************************************
* @author: Shuobin
* @date: 2024/3/20 17:39
* @version: 1.0
* @description: 邻接矩阵实现有向图
********************************************************************************/



#include "am_dir_graph.h"

AmDirGraph getAmDirGraph() {
    AmDirGraph g;
    g.vexNum = 0;
    for (int i = 0; i <= MAX_NODES - 1; i++) {
        g.vexes[i] = '\0';
    }
    return AmDirGraph();
}
