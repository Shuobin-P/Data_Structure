#include <iostream>
#include <vector>
#include <stack>
#include "src/nonlinear_list/seq_storage/graph/indirected_graph/am_indir_graph.h"

using namespace std;


int main() {
    AMIndGraph g = getGraph();
    addVex(g, '0');
    addVex(g, '1');
    addVex(g, '2');
    addVex(g, '3');
    addVex(g, '4');
    addArc(g, '0', '1');
    addArc(g, '0', '2');
    addArc(g, '0', '4');
    addArc(g, '1', '3');
    addArc(g, '2', '4');
    dfs(g, 2);
}