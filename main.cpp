#include<stdio.h>
#include ".\src\nonlinear_list\seq_storage\graph\directed_graph\al_dir_graph.h"

int main() {
    ALDirGraph g = getALDirGraph();
    addVex(g, 'A');
    addVex(g, 'B');
    addVex(g, 'C');
    addVex(g, 'D');
    addVex(g, 'E');
    addVex(g, 'F');
    addVex(g, 'G');
    addVex(g, 'H');
    addVex(g, 'I');
    addVex(g, 'J');

    addArc(g, 'A', 'B');
    addArc(g, 'A', 'C');
    addArc(g, 'A', 'D');
    addArc(g, 'B', 'E');
    addArc(g, 'E', 'I');
    addArc(g, 'C', 'F');
    addArc(g, 'F', 'J');
    addArc(g, 'C', 'G');
    addArc(g, 'A', 'D');
    addArc(g, 'D', 'H');
    int i = 0;
    int j = 9;
    printf("exist arc between %c and %c =%d", g.vexList[i].data, g.vexList[j].data, arcIsExist(g, i, j));


}




