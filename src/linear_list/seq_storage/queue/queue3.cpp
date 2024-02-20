/********************************************************************************
* @author: Shuobin
* @date: 2024/2/20 17:37
* @version: 1.0
* @description: queue的第三种实现方式，rear指向队尾元素的后一个位置，增加tag=0/1用于标记最近第一次操作是入队还是出队，1表示入队，0表示出队
********************************************************************************/
#include <malloc.h>
#include "queue3.h"

void init(Queue3 &queue) {
    queue.dataPtr = (int *) malloc(sizeof(int) * MAX_SIZE);
    queue.front = 0;
    queue.rear = 0;
    queue.tag = -1; //表示还未进行任何入队和出队操作
}

bool isEmpty(Queue3 &queue) {
    return queue.front == queue.rear && (queue.tag == -1 || queue.tag == 0);
}

bool isFull(Queue3 &queue) {
    return queue.front == queue.rear && queue.tag == 1;
}

bool enQueue(Queue3 &queue, int ele) {
    if(isFull(queue)) return false;
    queue.dataPtr[queue.rear] = ele;
    queue.rear = (queue.rear + 1) % MAX_SIZE;
    queue.tag = 1;
    return true;
}

bool deQueue(Queue3 &queue, int &holder) {
    if(isEmpty(queue)) return false;
    holder = queue.dataPtr[queue.front];
    queue.front = (queue.front + 1) % MAX_SIZE;
    queue.tag = 0;
    return true;
}
