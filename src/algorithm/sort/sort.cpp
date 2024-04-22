/********************************************************************************
* @author: Shuobin
* @date: 2024/4/19 16:54
* @version: 1.0
* @description: 排序算法实现
********************************************************************************/
#include<stdio.h>
#include "sort.h"


/**
 * 插入排序算法实现
 * @param arr
 * @param arrLen arr数组长度
 */
void insertionSort(int *arr, int arrLen) {
    for (int i = 1; i <= arrLen - 1; i++) {
        int tmp = arr[i];
        if (tmp >= arr[i - 1]) continue;
        int j = i - 1;
        for (; j >= 0; j--) { //把比tmp大的元素往后移
            if (tmp >= arr[j]) {
                break;
            } else if (tmp < arr[j]) {
                arr[j + 1] = arr[j];
            }
        }
        arr[j + 1] = tmp;
    }
}

/**
 * 希尔排序算法实现
 * @param arr
 * @param arrLen
 */
void shellSort(int *arr, int arrLen) {
    int gap = arrLen / 2;
    for (; gap >= 1; gap /= 2) { //通过leetcode运行，发现gap--好像效率更高
        for (int i = gap; i <= arrLen - 1; i++) { //注：这里是i++，而不是i+=gap，但是采用i+=gap需要改写算法
            int tmp = arr[i];
            if (tmp >= arr[i - gap]) continue;
            int j = i - gap;
            for (; j >= 0; j -= gap) { //把比tmp大的元素往后移
                if (tmp >= arr[j]) {
                    break;
                } else if (tmp < arr[j]) {
                    arr[j + gap] = arr[j];
                }
            }
            arr[j + gap] = tmp;
        }
    }
}
