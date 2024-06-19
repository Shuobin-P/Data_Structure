#include "../al_dir_graph.h"

/********************************************************************************
* @author: Shuobin
* @date: 2024/6/16 15:59
* @version: 1.0
* @description: 
********************************************************************************/

void init_graph() {
    ALDirGraph g = getALDirGraph();
    addVex(g, '1');
    addVex(g, '2');
    addVex(g, '3');
    addVex(g, '4');
    addVex(g, '5');
    addVex(g, '6');
    addArc(g, '1', '2');
    addArc(g, '3', '2');
    addArc(g, '3', '6');
    addArc(g, '4', '3');
    addArc(g, '4', '6');
    addArc(g, '6', '5');
    addArc(g, '6', '1');
}

