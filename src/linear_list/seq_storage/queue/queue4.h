/********************************************************************************
* @author: Shuobin
* @date: 2024/2/20 18:47
* @version: 1.0
* @description: queue的第四种实现方式，rear指向队尾元素，并且牺牲了一个存储单元。
********************************************************************************/



#ifndef DATA_STRUCTURE_QUEUE4_H
#define DATA_STRUCTURE_QUEUE4_H
#define MAX_SIZE 10


typedef struct Queue4 {
    int *dataPtr;
    int front, rear;
} Queue4;

void init(Queue4 &queue);

bool isEmpty(Queue4 &queue);

bool isFull(Queue4 &queue);

bool enQueue(Queue4 &queue, int ele);

bool deQueue(Queue4 &queue, int &holder);


#endif //DATA_STRUCTURE_QUEUE4_H
