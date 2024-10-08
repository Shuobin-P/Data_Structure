/********************************************************************************
* @author: Shuobin
* @date: 2024/2/18 14:40
* @version: 1.0
* @description: 
********************************************************************************/

#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H

typedef struct ArcNode {
    int val;
    struct ArcNode *nextArc;
    int maxCapacity;
    int nodeSize;
} ArcNode, *Stack;

void init(Stack &stack);

bool push(Stack &stack, int val);

bool pop(Stack &stack, int &holder);

bool getStackTop(Stack &stack, int &holder);

bool isEmpty(Stack &stack);

bool isFull(Stack &stack);

#endif //DATA_STRUCTURE_STACK_H
