/********************************************************************************
* @author: Shuobin
* @date: 2024/4/19 17:32
* @version: 1.0
* @description: 排序算法
********************************************************************************/
#ifndef DATA_STRUCTURE_SORT_H
#define DATA_STRUCTURE_SORT_H
#define KEEP_HEAP_OPT 2 //选择KEEP_HEAP算法 1：递归实现 2：非递归实现

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

/**
 * 堆排序
 * @param arr 待排序数组，arr[0]作为暂存区使用。
 * @param arrLen 数组长度，不包括arr[0]。
 */
void heapSort(int *arr, int arrLen);

#endif //DATA_STRUCTURE_SORT_H
