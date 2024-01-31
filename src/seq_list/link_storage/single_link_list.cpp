/********************************************************************************
* @author: Shuobin
* @date: 2024/1/31 15:16
* @version: 1.0
* @description: 
********************************************************************************/

#include <stdio.h>
#include <malloc.h>
#include "single_link_list.h"

LinkList init() {
    LNode *dummyNode = (LNode *)malloc(sizeof(LNode));
    return dummyNode;
}

bool initList(LinkList &list) {
    list = (LNode *)malloc(sizeof(LNode));
    list->next = NULL;
    return true;
}

bool insertAfterNode(LNode *p, int val) {
    if(p == NULL) return false;
    LNode *newNode = (LNode *)malloc(sizeof(LNode));
    newNode->val = val;
    newNode->next = p->next;
    p->next = newNode;
    return true;
}

bool insertBeforeNode(LNode *p, int val) {
    if(p == NULL) return false;
    int tmp = p->val;
    p->val = val;
    insertAfterNode(p, tmp);
    return true;
}

bool insertAtIndex(LinkList &list, int index, int val) {
    if (list == NULL) return false;
    LNode *p = list;
    int cnt = 1;
    while(cnt < index) {
        p = p->next;
        cnt++;
    }
    insertAfterNode(p, val);
    return true;
}

bool deleteAtIndex(LinkList &list, int index, int &deletedEleValHolder) {
    LNode *p = list;
    int cnt = 1;
    LNode *tmp;
    while(cnt < index) {
        p = p->next;
        cnt++;
    }
    deletedEleValHolder = p->next->val;
    tmp = p->next;
    p->next = p->next->next;
    free(tmp);
    return true;
}

bool deleteNode(LNode *p) {
    //说明p是尾节点
    if(p == NULL) return false;
    if(p->next == NULL) {
        free(p); //FIXME：单链表的尾节点->next这块空间里面的数据不是单链表的数据了。
    } else {
        //说明p不是尾节点
        //把P后面的数据赋值给前面的元素，然后删除尾节点。问题：我的实现方式比王道的实现时间复杂度更高
        p->val = p->next->val;
        LNode *tmp = p->next;
        p->next = p->next->next;
        free(tmp);
    }
    return true;
}

void traverseList(LinkList list) {
    LNode *p = list->next;
    printf("Traverse list result: ");
    while(p  != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

