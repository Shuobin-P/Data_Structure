/********************************************************************************
* @author: Shuobin
* @date: 2024/2/5 14:55
* @version: 1.0
* @description: 
********************************************************************************/
#include <malloc.h>
#include <stdio.h>
#include "double_link_list.h"

bool initDoubleLinkList(DouLinkList &list) {
    list = (DNode *) malloc(sizeof(DNode));
    if (list == NULL) return false;
    list->prior = NULL;
    list->next = NULL;
    return true;
}

DNode *createNode(int eleVal) {
    DNode *newNode = (DNode *) malloc(sizeof(DNode));
    if(newNode == NULL) return NULL;
    newNode->val = eleVal;
    newNode->prior = NULL;
    newNode->next = NULL;
    return newNode;
}

bool insertNodeAfterTarNode(DNode *targetNode, DNode *newNode) {
    if (targetNode == NULL) return false;
    newNode->next = targetNode->next;
    if (newNode->next != NULL) newNode->next->prior = newNode;
    targetNode->next = newNode;
    newNode->prior = targetNode;
    return true;
}

bool deleteNode(DNode *target) {
    //中间的一般节点
    if(target == NULL) return false;
    target->prior->next = target->next;
    if(target->next != NULL) target->next->prior = target->prior;
    free(target);
    return true;
}

void destroyList(DouLinkList &list) {
    DNode *ptr = list->next;
    while(ptr != NULL) {
        DNode *tmp = ptr->next;
        deleteNode(ptr);
        ptr = tmp;
    }
    free(list);
}

void traverseList(DouLinkList &list) {
    if(list == NULL) return;
    DNode *p = list->next;
    printf("Traverse Double list result: ");
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

