/********************************************************************************
* @author: Shuobin
* @date: 2024/2/20 17:09
* @version: 1.0
* @description: queue的第二种实现方式，rear指向队尾元素的后一个位置，增加size变量记录队列长度
********************************************************************************/
#ifndef DATA_STRUCTURE_QUEUE2_H
#define DATA_STRUCTURE_QUEUE2_H
#define MAX_SIZE 5

typedef struct Queue2 {
    int *dataPtr;
    int front, rear;
    int size;
} Queue2;

void init(Queue2 &queue);

bool isEmpty(Queue2 &queue);

bool isFull(Queue2 &queue);

bool enQueue(Queue2 &queue, int ele);

bool deQueue(Queue2 &queue, int &holder);
/**
 * 遍历队列
 * @param queue
 */
void traverse(Queue2 &queue);

#endif //DATA_STRUCTURE_QUEUE2_H
