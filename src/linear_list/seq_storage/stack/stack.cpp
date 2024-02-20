/********************************************************************************
* @author: Shuobin
* @date: 2024/2/16 20:56
* @version: 1.0
* @description: 
********************************************************************************/
#include<stdio.h>
#include<malloc.h>
#include "stack.h"

void init(Stack &stack) {
    stack.elePtr = (int *) malloc(sizeof(int) * MAX_SIZE);
    stack.eleSize = 0;
    stack.stackCapacity = MAX_SIZE;
}

bool isEmpty(Stack &stack) {
    return stack.eleSize == 0;
}

bool push(Stack &stack, int element) {
    if(stack.eleSize == stack.stackCapacity) return false;
    stack.elePtr[stack.eleSize] = element;
    stack.eleSize++;
    return true;
}

bool pop(Stack &stack, int &eleHolder) {
    if(stack.eleSize == 0) return false;
    eleHolder = stack.elePtr[stack.eleSize];
    stack.eleSize--;
    return true;
}

bool getStackTopEle(Stack &stack, int &topEleHolder) {
    if(stack.eleSize == 0) return false;
    topEleHolder = stack.elePtr[stack.eleSize - 1];
    return true;
}

void traverseStack(Stack &stack) {
    for (int i = stack.eleSize - 1; i >= 0; i--) {
        printf("%d ", stack.elePtr[i]);
    }
    printf("\n");
}

