/********************************************************************************
* @author: Shuobin
* @date: 2024/2/20 18:47
* @version: 1.0
* @description: queue的第四种实现方式，rear指向队尾元素，并且牺牲了一个存储单元。
********************************************************************************/
#include <malloc.h>
#include "queue4.h"

void init(Queue4 &queue) {
    queue.dataPtr = (int *) malloc(sizeof(int) * MAX_SIZE);
    queue.front = 0;
    queue.rear = MAX_SIZE - 1;
}

bool isEmpty(Queue4 &queue) {
    return queue.front == (queue.rear + 1) % MAX_SIZE;
}

bool isFull(Queue4 &queue) {
    return queue.front == (queue.rear + 2) % MAX_SIZE;
}

bool enQueue(Queue4 &queue, int ele) {
    if (isFull(queue)) return false;
    queue.rear = (queue.rear + 1) % MAX_SIZE;
    queue.dataPtr[queue.rear] = ele;
    return true;
}

bool deQueue(Queue4 &queue, int &holder) {
    if (isEmpty(queue)) return false;
    holder = queue.dataPtr[queue.front];
    queue.front = (queue.front + 1) % MAX_SIZE;
    return true;
}

