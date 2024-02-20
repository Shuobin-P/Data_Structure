/********************************************************************************
* @author: Shuobin
* @date: 2024/2/20 14:35
* @version: 1.0
* @description: queue的第一种实现方式，rear指向队尾元素的后一个位置，并且牺牲了一个存储单元。
********************************************************************************/


#include<malloc.h>
#include "queue1.h"

void init(Queue1 &queue) {
    queue.dataPtr = (int *) malloc(sizeof(int) * MAX_SIZE);
    queue.front = 0;
    queue.rear = 0;
}

bool isEmpty(Queue1 &queue) {
    return queue.front == queue.rear;
}

bool isFull(Queue1 &queue) {
    return (queue.rear + 1) % MAX_SIZE == queue.front;
}

bool enQueue(Queue1 &queue, int ele) {
    if(isFull(queue)) return false;
    queue.dataPtr[queue.rear] = ele;
    queue.rear = (queue.rear + 1) % MAX_SIZE;
    return true;
}

bool deQueue(Queue1 &queue, int &holder) {
    if(isEmpty(queue)) return false;
    holder = queue.dataPtr[queue.front];
    queue.front = (queue.front + 1) % MAX_SIZE;
    return true;
}

bool getFront(Queue1 &queue, int &holder) {
    if(isEmpty(queue)) return false;
    holder = queue.dataPtr[queue.front];
    return true;
}
