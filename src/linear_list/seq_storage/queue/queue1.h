/********************************************************************************
* @author: Shuobin
* @date: 2024/2/20 14:35
* @version: 1.0
* @description: queue的第一种实现方式，rear指向队尾元素的后一个位置，并且牺牲了一个存储单元。
********************************************************************************/
#ifndef DATA_STRUCTURE_QUEUE1_H
#define DATA_STRUCTURE_QUEUE1_H
#define MAX_SIZE 10

typedef struct Queue1 {
    int *dataPtr;
    int front, rear;
} Queue1;

void init(Queue1 &queue);

bool isEmpty(Queue1 &queue);

bool isFull(Queue1 &queue);
/**
 * 向队列中添加新的元素
 * @param queue
 * @param ele
 * @return true代表入队成功，false代表入队失败
 */
bool enQueue(Queue1 &queue, int ele);

/**
 * 将队头元素移除
 * @param queue
 * @param holder 保存队头元素的值
 * @return
 */
bool deQueue(Queue1 &queue, int &holder);

/**
 * 获得队头元素
 * @param queue
 * @param holder
 * @return
 */
bool getFront(Queue1 &queue, int &holder);
#endif //DATA_STRUCTURE_QUEUE1_H
