/********************************************************************************
* @author: Shuobin
* @date: 2024/1/31 15:26
* @version: 1.0
* @description: 
********************************************************************************/
#include <stdio.h>
#include <malloc.h>
#include "seq_list.h"

/**
 * 采取线性存储且能够动态分配空间的线性表
 */
void init_list(List *&list) {
    //*list = (List) {(int *) malloc(sizeof(int) * INITIAL_SIZE), 0};
    list = (List *) malloc(sizeof(List));
    list->dataArr = (int *) malloc(sizeof(int) * INITIAL_SIZE);
    list->length = 0;
}

/**
 * 对原数组进行扩容
 * @param originArr
 * @param size 增量
 * @return 新的数组起始地址
 */
int *resize(int *originArr, int size) {
    return NULL;
}

bool isFull(List *list) {
    if (INITIAL_SIZE <= list->length) {
        return true;
    }
    return false;
}

/**
 * Adding element at the end of the vexList
 * @param list Target vexList
 * @param e Element
 */
void addElementAtEnd(List *list, int e) {
    if (isFull(list)) {
        list->dataArr = resize(list->dataArr, 5);
    }
    list->dataArr[list->length] = e;
    list->length++;
}

/**
 * Adding Element By specifying index
 * @param list
 * @param index Range from 0 to any positive num
 * @param e Target Element
 */
void addElementAtIndex(List *list, int index, int e) {
    int p = list->length - 1; //指向线性表最后一个元素
    if (isFull(list)) {
        list->dataArr = resize(list->dataArr, 5);
    }
    if (index > list->length - 1) {         //防止index超过已有线性表已有的元素的下标
        list->dataArr[list->length] = e;
    } else if (index <= list->length - 1) { //把index对应元素以及后面的元素全部往后移
        while (p >= index) {
            list->dataArr[p + 1] = list->dataArr[p];
            p--;
        }
        if (p == -1) p++;
        list->dataArr[p] = e;
    }
    list->length++;
}

void printList(List *list) {
    if (list == NULL) return;
    printf("List's dataArr: ");
    for (int i = 0; i <= list->length - 1; i++) {
        printf("%d ", list->dataArr[i]);
    }
    printf("\n");
}

/**
 * 按下标删除
 * @param index 元素下标
 */
int deleteElementByIndex(List *list, int index) {
    int elementVal = list->dataArr[index];
    int p = index;
    while (p < list->length - 1) {
        list->dataArr[p] = list->dataArr[p + 1];
        p++;
    }
    list->length--;
    return elementVal;
}

void destroyList(List *&list) {
    free(list);
    list = NULL;
}

bool isEmpty(List *list) {
    if (list == NULL || list->length == 0) return true;
    return false;
}

/**
 * 按值删除
 * @param target 要删除的目标值
 */
void deleteElementByVal(int target) {

}

void updateElementByIndex(int i) {


}

void findByIndex(int i) {

}

void findByVal(int val) {

}




