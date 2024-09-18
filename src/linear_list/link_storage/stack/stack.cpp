/********************************************************************************
* @author: Shuobin
* @date: 2024/2/18 14:49
* @version: 1.0
* @description: 
********************************************************************************/

#include <stdio.h>
#include <malloc.h>
#include "stack.h"

void init(Stack &stack) {
    stack = (ArcNode *) malloc(sizeof(ArcNode));
    stack->val = -1;
    stack->nextArc = NULL;
    stack->maxCapacity = 10;
    stack->nodeSize = 0;
}

bool push(Stack &stack, int val) {
    if(isFull(stack)) return false;
    ArcNode *newNode = (ArcNode *) malloc(sizeof(ArcNode));
    newNode->val = val;
    newNode->nextArc = stack->nextArc;
    stack->nextArc = newNode->nextArc;
    stack->nodeSize++;
    return true;
}

bool pop(Stack &stack, int &holder) {
    if(isEmpty(stack)) return false;
    ArcNode *tmp = stack->nextArc;
    stack->nextArc = stack->nextArc->nextArc;
    holder = tmp->val;
    free(tmp);
    stack->nodeSize--;
    return true;
}

bool getStackTop(Stack &stack, int &holder) {
    if(!isEmpty(stack)) {
        holder = stack->nextArc->val;
        return true;
    }
    return false;
}

bool isEmpty(Stack &stack) {
    return stack->nextArc == NULL;
}

bool isFull(Stack &stack) {
    return stack->nodeSize == stack->maxCapacity;
}

