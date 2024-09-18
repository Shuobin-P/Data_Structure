/********************************************************************************
* @author: Shuobin
* @date: 2024/1/31 15:16
* @version: 1.0
* @description: 单链表的定义以及相关操作
********************************************************************************/


#ifndef PROJECT1_SINGLE_LINKED_LIST_H
#define PROJECT1_SINGLE_LINKED_LIST_H
typedef struct LNode {
    int val;
    struct LNode *next;
} LNode, *LinkList;

/**
 * 采用无dummy结点的方式创建链表
 * @param linkList
 * @return true: 初始化成功， false: 初始化失败
 */
bool initListNoDummy(LinkList &linkList);

/**
 * 将dummy结点作为单链表的头结点
 * @param linkList
 * @return true: 初始化成功， false: 初始化失败
 */
bool initListDummyHead(LinkList &linkList);

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
__attribute__((deprecated)) bool deleteAtIndex(LinkList &list, int index, int &deletedEleValHolder);

/**
 * 删除指定位置处的结点
 * @param list
 * @param index index>0
 * @param holder 保存被删除的元素的值
 * @return true: 删除成功 false: 删除失败
 */
bool listDelete(LinkList &list, int index, int &holder);

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
 * 通过尾插法创建不带dummy头节点的单链表，把用户输入的值作为新节点的值插入到单链表
 * @param list
 */
void createListByInsertTailWithoutDummyHead(LinkList &list);

/**
 * 遍历输出含dummy头节点的单链表
 * @param list
 */
void traverseList(LinkList list);

/**
 * 获得list的长度
 * @param list
 */
int length(LinkList &list);

/**
 * 判断链表是否为空
 * @param list
 * @return true: 链表为空 false: 链表不为空
 */
bool isEmpty(LinkList &list);

/**
 * 回收链表占用的内存空间。C语言没有垃圾回收机制，因此需要手动处理，或者使用第三方库。
 * @param list
 */
void destroyList(LinkList &list);

#endif //PROJECT1_SINGLE_LINKED_LIST_H

