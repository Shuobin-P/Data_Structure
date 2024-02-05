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
        free(p); //FIXME 遍历单链表的时候会出现遍历不完的情况。原因：单链表的尾节点->next这块空间里面的数据不是单链表的数据，因此出现野指针。
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

LNode *getNodeByIndex(LinkList list, int index) {
    int cnt = 0;
    LNode *p = list;
    if(index <= 0) return NULL;
    while(p!= NULL && cnt < index) {
        p = p->next;
        cnt++;
    }
    return p;
}

LNode *getNodeByVal(LinkList list, int targetVal) {
    LNode *p = list;
    while(p!= NULL) {
        if(p->val == targetVal) return p;
        else p = p->next;
    }
    return NULL;
}

void createListByInsertHead(LinkList &list) {
    int inputVal = 0;
    initList(list);
    //用户输入一个元素就是在单链表上插入一个节点
    printf("Please input the node val. If you input 111111, the process will be ended.\n");
    scanf("%d", &inputVal);
    while(inputVal != 111111) {
        insertAfterNode(list, inputVal);
        scanf("%d", &inputVal);
    }
}

void createListByInsertTail(LinkList &list) {
    int inputVal = 0;
    //初始化单链表
    initList(list);
    LNode *tailPtr = list;
    printf("Please input the node val. If you input 111111, the process will be ended.\n");
    scanf("%d", &inputVal);
    while(inputVal != 111111) {
        insertAfterNode(tailPtr, inputVal);
        tailPtr = tailPtr->next;
        scanf("%d", &inputVal);
    }
}

void createListByInsertTailWithoutDummyHead(LinkList &list) {
    int inputVal = 0;
    LNode *tailPtr = NULL;
    printf("Please input the node val. If you input 111111, the process will be ended.\n");
    scanf("%d", &inputVal);
    if(inputVal != 111111) {
        LNode *newNodePtr = (LNode *)malloc(sizeof(LNode));
        newNodePtr->val = inputVal;
        newNodePtr->next = NULL;
        list = newNodePtr;
        tailPtr = list;
    } else {
        return;
    }
    scanf("%d", &inputVal);
    while(inputVal != 111111) {
        insertAfterNode(tailPtr, inputVal);
        tailPtr = tailPtr->next;
        scanf("%d", &inputVal);
    }
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

