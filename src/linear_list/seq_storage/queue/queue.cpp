/********************************************************************************
* @author: Shuobin
* @date: 2024/2/20 14:35
* @version: 1.0
* @description: 
********************************************************************************/


#include<malloc.h>
#include "queue.h"

void init(Queue &queue) {
    queue.dataPtr = (int *) malloc(sizeof(int) * MAX_SIZE);
    queue.front = 0;
    queue.rear = 0;
}

bool isEmpty(Queue &queue) {
    return queue.front == queue.rear;
}

bool isFull(Queue &queue) {
    return (queue.rear + 1) % MAX_SIZE == queue.front;
}

bool enQueue(Queue &queue, int ele) {
    if(isFull(queue)) return false;
    queue.dataPtr[queue.rear] = ele;
    queue.rear = (queue.rear + 1) % MAX_SIZE;
    return true;
}

bool deQueue(Queue &queue, int &holder) {
    if(isEmpty(queue)) return false;
    holder = queue.dataPtr[queue.front];
    queue.front = (queue.front + 1) % MAX_SIZE;
    return true;
}

bool getFront(Queue &queue, int &holder) {
    if(isEmpty(queue)) return false;
    holder = queue.dataPtr[queue.front];
    return true;
}
