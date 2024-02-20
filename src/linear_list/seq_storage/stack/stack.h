/********************************************************************************
* @author: Shuobin
* @date: 2024/2/16 20:09
* @version: 1.0
* @description: 栈的顺序存储实现
********************************************************************************/
#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H
#define MAX_SIZE 10

typedef struct Stack{
    int *elePtr;
    int eleSize; //已有的元素数量
    int stackCapacity;   //栈的最大容量
} Stack;

/**
 * 栈的初始化
 * @param stack
 */
void init(Stack &stack);

/**
 * 判断栈是否为空
 * @param stack
 * @return
 */
bool isEmpty(Stack &stack);

/**
 * 入栈
 * @param stack
 * @param element
 * @return
 */
bool push(Stack &stack, int element);

/**
 * 出栈
 * @param stack
 * @param elementHolder 保存栈顶元素
 * @return
 */
bool pop(Stack &stack, int &eleHolder);

/**
 * 获得栈顶元素
 * @param stack
 * @param topEleHolder 保存栈顶元素的容器
 * @return
 */
bool getStackTopEle(Stack &stack, int &topEleHolder);

/**
 * 栈的遍历
 * @param stack
 */
void traverseStack(Stack &stack);
#endif //DATA_STRUCTURE_STACK_H
