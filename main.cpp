#include<stdio.h>
#include ".\src\nonlinear_list\seq_storage\graph\indirected_graph\al_indir_graph.h"

int main() {
    ALGraph g = getALGraph();
    addVex(g, '1');
    addVex(g, '2');
    addVex(g, '3');
    addVex(g, '4');
    addVex(g, '5');
    addVex(g, '6');
    addVex(g, '7');
    addVex(g, '8');

    addArc(g, '2', '1');
    addArc(g, '2', '6');
    addArc(g, '1', '5');
    addArc(g, '6', '3');
    addArc(g, '6', '7');
    addArc(g, '3', '4');
    addArc(g, '3', '7');
    addArc(g, '7', '4');
    addArc(g, '7', '8');
    addArc(g, '4', '8');
    bfsMinDistance(g, 1);

}




