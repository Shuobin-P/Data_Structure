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

    addArc(g, 'A', 'B');
//    addArc(g, 'A','C');
//    addArc(g, 'A','D');
//    addArc(g, 'B','E');
//    addArc(g, 'E','I');
//    addArc(g, 'C','F');
//    addArc(g, 'C','G');
//    addArc(g, 'F','J');
//    addArc(g, 'D','H');
    //FIXME vexList[0]保存了图的第一个结点:A，g.vexList[0].firstArc指向第一个边结点，存储了结点B的下标，g.vexList[0].firstArc->i的值理论上为1，但实际运行
    // 结果不是；而且下面两句相同的打印语句，同一个变量g.vexList[0].firstArc->i的值竟然不一样。
    printf("5: %p %d\n", g.vexList[0].firstArc, g.vexList[0].firstArc->i);
    printf("6: %p %d\n", g.vexList[0].firstArc, g.vexList[0].firstArc->i);
    printf("1: vex[0]=%c\n", g.vexList[0].data);
}




