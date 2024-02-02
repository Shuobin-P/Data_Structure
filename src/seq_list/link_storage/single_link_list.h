/********************************************************************************
* @author: Shuobin
* @date: 2024/1/31 15:16
* @version: 1.0
* @description: 实现单链表以及相关操作
********************************************************************************/


#ifndef PROJECT1_SINGLE_LINKED_LIST_H
#define PROJECT1_SINGLE_LINKED_LIST_H
typedef struct LNode{
    int val;
    struct LNode *next;
}LNode, *LinkList;

/**
 * 创建含有头(dummy)节点的初始空链表
 * @param list 未初始化的空链表
 */
LinkList init();

/**
 * 使用C++的引用&实现单链表的初始化
 * @param linkList
 * @return 初始化是否成功
 */
bool initList(LinkList &linkList);
/**
 * 在指定节点后插入新的节点
 * @param p
 * @param val
 * @return 是否插入成功
 */
bool insertAfterNode(LNode *p, int val);

/**
 * 在指定结点之前插入节点
 * @param list
 * @param p
 * @param val
 * @return
 */
bool insertBeforeNode(LNode *p, int val);

/**
 * 在指定位置（从1开始）插入节点
 * @param list
 * @param index
 * @param val
 * @return 是否插入成功
 */
bool insertAtIndex(LinkList &list, int index, int val);

/**
 * 删除指定位置的元素
 * @param list
 * @param index
 * @param deletedEleHolder 保存被删除的元素的值
 * @return
 */
bool deleteAtIndex(LinkList &list, int index, int &deletedEleValHolder);

/**
 * 删除给定地址的节点
 * @param p
 * @return
 */
bool deleteNode(LNode *p);

/**
 * 获得指定位置的节点
 * @param list
 * @param index 从1开始计数的位置
 * @return
 */
LNode *getNodeByIndex(LinkList list, int index);

/**
 * 根据指定的值查找节点
 * @param list
 * @param targetVal
 * @return
 */
LNode *getNodeByVal(LinkList list, int targetVal);

/**
 * 通过头插法创建带dummy头节点的单链表，把用户输入的值作为新节点的值插入到单链表
 * @param list
 */
void createListByInsertHead(LinkList &list);

/**
 * 通过尾插法创建带dummy头节点的单链表，把用户输入的值作为新节点的值插入到单链表
 * @param list
 */
void createListByInsertTail(LinkList &list);
/**
 * 遍历输出单链表
 * @param list
 */
void traverseList(LinkList list);
#endif //PROJECT1_SINGLE_LINKED_LIST_H

