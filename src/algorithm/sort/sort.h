/********************************************************************************
* @author: Shuobin
* @date: 2024/4/19 17:32
* @version: 1.0
* @description: 排序算法
********************************************************************************/
#ifndef DATA_STRUCTURE_SORT_H
#define DATA_STRUCTURE_SORT_H

/**
 * 插入排序算法实现
 * @param arr
 * @param arrLen arr数组长度
 */
void insertionSort(int *arr, int arrLen);

/**
 * 希尔排序算法实现
 * @param arr
 * @param arrLen
 */
void shellSort(int *arr, int arrLen);

/**
 * 冒泡排序算法实现
 * @param arr
 * @param arrLen
 * @param opt 1：结果升序排列 2：结果降序排列
 */
void bubbleSort(int *arr, int arrLen, short opt);

/**
 * 快速排序算法实现
 * @param arr
 * @param arrLen
 */
void quickSort(int *arr, int arrLen);

#endif //DATA_STRUCTURE_SORT_H
