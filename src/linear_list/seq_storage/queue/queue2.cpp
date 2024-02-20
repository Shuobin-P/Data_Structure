/********************************************************************************
* @author: Shuobin
* @date: 2024/2/20 17:09
* @version: 1.0
* @description: queue的第二种实现方式，rear指向队尾元素的后一个位置，增加size变量记录队列长度
********************************************************************************/
#include <stdio.h>
#include <malloc.h>
#include "queue2.h"

void init(Queue2 &queue) {
    queue.dataPtr = (int *) malloc(sizeof(int) * MAX_SIZE);
    queue.front = 0;
    queue.rear = 0;
    queue.size = 0;
}

bool isEmpty(Queue2 &queue) {
    return queue.size == 0;
}

bool isFull(Queue2 &queue) {
    return queue.size == MAX_SIZE;
}

bool enQueue(Queue2 &queue, int ele) {
    if (isFull(queue)) return false;
    queue.dataPtr[queue.rear] = ele;
    queue.rear = (queue.rear + 1) % MAX_SIZE;
    queue.size++;
    return true;
}

bool deQueue(Queue2 &queue, int &holder) {
    if (isEmpty(queue)) return false;
    holder = queue.dataPtr[queue.front];
    queue.front = (queue.front + 1) % MAX_SIZE;
    queue.size--;
    return true;
}

void traverse(Queue2 &queue) {
    //从front到一直到rear
    int ptr = queue.front;
    int sizeTmp = queue.size;
    while(sizeTmp > 0) {
        printf("%d ", queue.dataPtr[ptr]);
        sizeTmp--;
        ptr++;
        if(ptr == MAX_SIZE) {
            ptr = ptr % MAX_SIZE;
        }
    }
    printf("\n");
}

