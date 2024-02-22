/********************************************************************************
* @author: Shuobin
* @date: 2024/2/20 20:44
* @version: 1.0
* @description: 实现链式存储并且带头节点的队列
********************************************************************************/
#include <malloc.h>
#include <stdio.h>
#include "queue.h"

void init(Queue &queue) {
    queue.front = queue.rear = (QNode *) malloc(sizeof(QNode));
    queue.front->next = NULL;
}

bool isEmpty(Queue &queue) {
    return queue.front->next == NULL && queue.rear->next == NULL;
}

bool enQueue(Queue &queue, int ele) {
    QNode *newNode = (QNode *) malloc(sizeof(QNode));
    if(newNode == NULL) return false;
    newNode->data = ele;
    newNode->next = NULL;
    queue.rear->next = newNode;
    queue.rear = newNode;
    return true;
}

bool deQueue(Queue &queue, int &holder) {
    if(isEmpty(queue)) return false;
    QNode *delNode = queue.front->next;
    queue.front->next = delNode->next;
    holder = delNode->data;
    if(queue.rear == delNode) {
        queue.rear = queue.front;
    }
    free(delNode);
    return true;
}
