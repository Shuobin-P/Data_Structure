#include <stdio.h>
#include ".\src\nonlinear_list\seq_storage\graph\indirected_graph\al_indir_graph.h"

int main() {
    ALGraph g = getALGraph();
    addVex(g, 'A');
    addVex(g, 'B');
//    addVex(g, 'C');
//    addVex(g, 'D');
//    addVex(g, 'E');
//    addVex(g, 'F');
//    addVex(g, 'G');
//    addVex(g, 'H');
//    addVex(g, 'I');
//    addVex(g, 'J');

    addArc(g, 'A','B');
//    addArc(g, 'A','C');
//    addArc(g, 'A','D');
//    addArc(g, 'B','E');
//    addArc(g, 'E','I');
//    addArc(g, 'C','F');
//    addArc(g, 'C','G');
//    addArc(g, 'F','J');
//    addArc(g, 'D','H');
    //问题：g.vexList[0].firstArc->next
    printf("1: %p\n", g.vexList[0].firstArc->next);
    printf("After\n");
    printf("2: %p\n", g.vexList[0].firstArc->next);

    if(g.vexList[0].firstArc->next != NULL) {
        printf("A's neightbour arcnode's NEXT PTR changed when vexIdx = %d, and it changed to= %p\n",-1 , g.vexList[0].firstArc->next);
    }
    dfs(g);

}




