/********************************************************************************
* @author: Shuobin
* @date: 2024/2/20 14:35
* @version: 1.0
* @description: queue的第一种实现方式，rear指向队尾元素的后一个位置，并且牺牲掉了一个存储单元。
********************************************************************************/
#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H
#define MAX_SIZE 10

typedef struct Queue {
    int *dataPtr;
    int front, rear;
} Queue;

void init(Queue &queue);

bool isEmpty(Queue &queue);

bool isFull(Queue &queue);
/**
 * 向队列中添加新的元素
 * @param queue
 * @param ele
 * @return true代表入队成功，false代表入队失败
 */
bool enQueue(Queue &queue, int ele);

bool deQueue(Queue &queue, int &holder);

bool getFront(Queue &queue, int &holder);
#endif //DATA_STRUCTURE_QUEUE_H
