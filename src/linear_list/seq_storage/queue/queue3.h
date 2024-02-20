/********************************************************************************
* @author: Shuobin
* @date: 2024/2/20 17:37
* @version: 1.0
* @description: queue的第三种实现方式，rear指向队尾元素的后一个位置，增加tag=0/1用于标记最近第一次操作是入队还是出队
********************************************************************************/
#ifndef DATA_STRUCTURE_QUEUE3_H
#define DATA_STRUCTURE_QUEUE3_H
#define MAX_SIZE 10

typedef struct Queue3 {
    int *dataPtr;
    int front, rear;
    int tag;
} Queue3;

void init(Queue3 &queue);

bool isEmpty(Queue3 &queue);

bool isFull(Queue3 &queue);

bool enQueue(Queue3 &queue, int ele);

bool deQueue(Queue3 &queue, int &holder);

#endif //DATA_STRUCTURE_QUEUE3_H
