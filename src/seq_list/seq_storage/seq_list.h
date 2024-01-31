/********************************************************************************
* @author: Shuobin
* @date: 2024/1/31 15:27
* @version: 1.0
* @description: 
********************************************************************************/

#ifndef PROJECT1_LIST_H
#define PROJECT1_LIST_H
#define INITIAL_SIZE 10
/**
 * 采用顺序存储且能够动态分配空间的线性表
 */

typedef struct {
    int *dataArr;
    int length; //已有元素的数量
} List;

void init_list(List* list);
void addElementAtEnd(List *list, int e);
void addElementAtIndex(List *list, int index, int e);
int deleteElementByIndex(List *list, int index);
void printList(List *list);

#endif //PROJECT1_LIST_H

