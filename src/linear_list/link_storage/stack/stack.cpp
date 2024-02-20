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
    stack = (Node *) malloc(sizeof(Node));
    stack->val = -1;
    stack->next = NULL;
    stack->maxCapacity = 10;
    stack->nodeSize = 0;
}

bool push(Stack &stack, int val) {
    if(isFull(stack)) return false;
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = stack->next;
    stack->next = newNode->next;
    stack->nodeSize++;
    return true;
}

bool pop(Stack &stack, int &holder) {
    if(isEmpty(stack)) return false;
    Node *tmp = stack->next;
    stack->next = stack->next->next;
    holder = tmp->val;
    free(tmp);
    stack->nodeSize--;
    return true;
}

bool getStackTop(Stack &stack, int &holder) {
    if(!isEmpty(stack)) {
        holder = stack->next->val;
        return true;
    }
    return false;
}

bool isEmpty(Stack &stack) {
    return stack->next == NULL;
}

bool isFull(Stack &stack) {
    return stack->nodeSize == stack->maxCapacity;
}

