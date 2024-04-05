#include<stdio.h>
#include ".\src\nonlinear_list\seq_storage\graph\directed_graph\am_dir_graph.h"

int main() {
    AmDirGraph g = getAmDirGraph();
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
    dfs(g,1);
    dfs(g,2);


}




