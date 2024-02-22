/********************************************************************************
* @author: Shuobin
* @date: 2024/2/20 20:44
* @version: 1.0
* @description: 实现链式存储并且带头节点的队列
********************************************************************************/
#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H
typedef struct QNode {
    int data;
    struct QNode *next;
}QNode;

typedef struct {
    QNode *front, *rear;
}Queue;

void init(Queue &queue);

bool isEmpty(Queue &queue);

bool enQueue(Queue &queue, int ele);

bool deQueue(Queue &queue, int &holder);
#endif //DATA_STRUCTURE_QUEUE_H
