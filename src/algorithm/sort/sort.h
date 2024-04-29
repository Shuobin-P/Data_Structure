/********************************************************************************
* @author: Shuobin
* @date: 2024/4/19 17:32
* @version: 1.0
* @description: 排序算法
********************************************************************************/
#ifndef DATA_STRUCTURE_SORT_H
#define DATA_STRUCTURE_SORT_H
#define KEEP_MAX_HEAP_OPT 2 //选择KEEP_MAX_HEAP算法 1：递归实现 2：非递归实现

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

/**
 * 归并排序
 * @param arr 存储了未排序数据的数组
 * @param arrLen arr数组的长度
 * @param newArr 和arr长度一致的新数组
 * @param opt 1: 将arr中的数据归并排序后，已排序序列存储在newArr中 2: 对arr进行归并排序后的数据依然存储在arr中，而不是在newArr中
 */
void mergeSort(int *arr, int arrLen, int *newArr, short opt);

#endif //DATA_STRUCTURE_SORT_H
