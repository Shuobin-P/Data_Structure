#include <stdio.h>
#include ".\src\nonlinear_list\seq_storage\graph\indirected_graph\am_indir_graph.h"

int main() {
    AMIndGraph g = createGraph();
    insertNode(g, '1');
    insertNode(g, '2');
    insertNode(g, '3');
    insertNode(g, '4');
    insertNode(g, '5');
    insertNode(g, '6');
    insertNode(g, '7');
    insertNode(g, '8');
    insertNode(g, '9');
    insertNode(g, '0');
    insertNode(g, 'A');
    insertNode(g, 'B');
    insertNode(g, 'C');
    insertNode(g, 'E');

    insertEdge(g, '1','2');
    insertEdge(g, '1','3');
    insertEdge(g, '1','4');
    insertEdge(g, '2','5');
    insertEdge(g, '3','6');
    insertEdge(g, '3','7');
    insertEdge(g, '4','8');
    insertEdge(g, '5','9');
    insertEdge(g, '6','0');
    insertEdge(g, 'A','B');
    insertEdge(g, 'A','C');
    insertEdge(g, 'B','E');

    dfs(g, 1);


}




