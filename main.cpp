#include ".\src\nonlinear_list\seq_storage\graph\indirected_graph\al_indir_graph.h"

int main() {
    ALGraph g = getALGraph();
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
    addVex(g, '1');
    addVex(g, '2');
    addVex(g, '3');

    addArc(g, 'A', 'B');
    addArc(g, 'A', 'C');
    addArc(g, 'A', 'D');
    addArc(g, 'B', 'E');
    addArc(g, 'E', 'I');
    addArc(g, 'C', 'F');
    addArc(g, 'C', 'G');
    addArc(g, 'F', 'J');
    addArc(g, 'D', 'H');
    addArc(g, '1', '2');
    addArc(g, '1', '3');
    addArc(g, '2', '3');
    addArc(g, 'F', 'G');

    dfs(g, 2);
}




