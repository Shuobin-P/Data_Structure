/********************************************************************************
* @author: Shuobin
* @date: 2024/2/5 12:19
* @version: 1.0
* @description: 双链表的定义及相关操作的实现。
********************************************************************************/

#ifndef DATA_STRUCTURE_DOUBLE_LINK_LIST_H
#define DATA_STRUCTURE_DOUBLE_LINK_LIST_H

typedef struct DNode {
    int val;
    struct DNode *prior;
    struct DNode *next;
} DNode, *DouLinkList;

/**
 * 初始化带dummy头节点的双链表
 * @param list
 * @return 初始化是否成功
 */
bool initDoubleLinkList(DouLinkList &list);

/**
 * 创建新节点
 * @param eleVal 新节点的元素值
 * @return 新节点的地址
 */
DNode* createNode(int eleVal);
/**
 * 在目标节点后插入新的节点
 * @param targetNode 目标节点
 * @param newNode 要插入的新节点
 * @return 插入是否成功
 */
bool insertNodeAfterTarNode(DNode *targetNode, DNode *newNode);

/**
 * 删除目标节点
 * @param target 待删除的目标节点指针
 * @return 删除操作是否成功
 */
bool deleteNode(DNode *target);

/**
 * 释放双链表占据的空间
 * @param list 目标双链表
 */
void destroyList(DouLinkList &list);

/**
 * 遍历打印双链表
 * @param list 目标双链表
 */
void traverseList(DouLinkList &list);
#endif //DATA_STRUCTURE_DOUBLE_LINK_LIST_H
